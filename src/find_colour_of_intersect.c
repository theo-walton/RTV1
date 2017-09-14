/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colour_of_intersect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 16:27:01 by twalton           #+#    #+#             */
/*   Updated: 2017/09/10 16:27:01 by twalton          ###   ########.fr       */
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

	dist = get_distance(&intersect->intersect, light);
	dist = 50000 / (dist * dist);
	if ((red = light->red * dist) > 255)
		red = 255;
	if ((blue = light->blue * dist) > 255)
		blue = 255;
	if ((green = light->green * dist) > 255)
		green = 255;
	red = red * intersect->object->red / 255;
	blue = blue * intersect->object->blue / 255;
	green = green * intersect->object->green / 255;
	return ((int)blue + (int)green * 256 + (int)red * 65536);
}

static int	combine_colours(int col1, int col2)
{
	double red;
	double green;
	double blue;

	blue = ((char*)&col1)[0] + ((char*)&col2)[0];
	green = ((char*)&col1)[1] + ((char*)&col2)[1];
	red = ((char*)&col1)[2] + ((char*)&col2)[2];
	return (col1);
	return ((int)blue + (int)green * 256 + (int)red * 65536);
}

int	find_colour_of_intersect(t_intersect *intersect, t_object *objects, t_light *lights)
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
			colour2 = combine_colours(colour1, colour2);
		}
		++i;
	}
	return (colour2);
}
