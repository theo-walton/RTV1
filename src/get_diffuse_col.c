/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_diffuse_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 19:37:07 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:00:24 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	get_sqr_distance(t_coor *coor, t_light *light)
{
	double sum;

	sum = 0;
	sum += (light->x - coor->x) * (light->x - coor->x);
	sum += (light->y - coor->y) * (light->y - coor->y);
	sum += (light->z - coor->z) * (light->z - coor->z);
	return (sum);
}

static void		intersect_colour(t_colour *result,
				t_intersect *intersect, t_light *light)
{
	double dist;
	double light_modifier;

	light_modifier = get_light_modifier(intersect, light);
	dist = get_sqr_distance(&(intersect->intersect), light);
	light_modifier *= DECAY_CONST / (dist);
	light_modifier *= (100 - intersect->object->shine) / 100.0;
	result->red = light->red * light_modifier;
	result->green = light->green * light_modifier;
	result->blue = light->blue * light_modifier;
	result->red *= intersect->object->red / 255.0;
	result->green *= intersect->object->green / 255.0;
	result->blue *= intersect->object->blue / 255.0;
}

void			get_diffuse_col(t_colour *result, t_intersect *intersect,
					t_object *objects, t_light *lights)
{
	int			i;
	t_colour	col1;

	i = 0;
	zero_colour(result);
	if (!intersect)
		return ;
	while (lights[i].red != -1)
	{
		if (path_to_light(intersect->intersect, objects, lights + i))
		{
			intersect_colour(&col1, intersect, lights + i);
			colour_sum(result, col1, *result);
		}
		++i;
	}
}
