/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 20:44:07 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:40:59 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	dist_to_col(t_colour *result, double dist,
				t_light *light, double shine)
{
	result->red = light->red * SHINE_CONST * shine / (dist * dist * 100);
	result->green = light->green * SHINE_CONST * shine / (dist * dist * 100);
	result->blue = light->blue * SHINE_CONST * shine / (dist * dist * 100);
}

static int	correct_direction(t_light light, t_coor point, t_coor reflect)
{
	t_coor temp;

	temp.x = light.x - point.x;
	temp.y = light.y - point.y;
	temp.z = light.z - point.z;
	if (dot_product(temp, reflect) < 0)
		return (0);
	return (1);
}

void		get_shine(t_colour *result, t_intersect *intersect,
				t_object *objects, t_light *lights)
{
	t_coor		reflect;
	double		dist;
	t_colour	col;
	int			i;

	i = 0;
	zero_colour(result);
	get_reflection(&reflect, &(intersect->vector), intersect);
	while (lights[i].red != -1)
	{
		if (correct_direction(lights[i], intersect->intersect, reflect) &&
			path_to_light(intersect->intersect, objects, lights + i))
		{
			dist = get_line_point_distance(&reflect,
				&(intersect->intersect), lights + i);
			dist_to_col(&col, dist, lights + i, intersect->object->shine);
			colour_sum(result, col, *result);
		}
		++i;
	}
}
