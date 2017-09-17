/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_diffuse_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 19:37:07 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 19:37:07 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	get_distance(t_coor *coor, t_light *light)
{
	double sum;

	sum = 0;
	sum += (light->x - coor->x) * (light->x - coor->x);
	sum += (light->y - coor->y) * (light->y - coor->y);
	sum += (light->z - coor->z) * (light->z - coor->z);
	return (sqrt(sum));
}

static int	intersect_colour(t_intersect *intersect, t_light *light)
{
	double red;
	double blue;
	double green;
	double dist;
	double light_modifier;

	light_modifier = get_light_modifier(intersect, light);
	dist = get_distance(&intersect->intersect, light);
	light_modifier *= 50000 / (dist * dist);
	red = light->red * light_modifier;
	blue = light->blue * light_modifier;
	green = light->green * light_modifier;
	if ((red = red * intersect->object->red / 255) > 255)
		red = 255;
	if ((blue = blue * intersect->object->blue / 255) > 255)
		blue = 255;
	if ((green = green * intersect->object->green / 255) > 255)
		green = 255;
	return ((int)blue + (int)green * 256 + (int)red * 65536);
}

int	get_diffuse_col(t_intersect *intersect, t_object *objects, t_light *lights)
{
	int i;
	int colour1;
	int colour2;

	i = 0;
	colour2 = 0;
	if (!intersect)
		return (0);
	while (lights[i].red != -1)
	{
		if (path_to_light(intersect->intersect, objects, lights + i))
		{
			colour1 = intersect_colour(intersect, lights + i);
			colour2 = colour_sum(colour1, colour2);
		}
		++i;
	}
	return (colour2);
}
