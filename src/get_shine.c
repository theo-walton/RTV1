/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 20:44:07 by twalton           #+#    #+#             */
/*   Updated: 2017/09/17 20:44:07 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	dist_to_col(double dist, t_light *light, double shine)
{
	int red;
	int green;
	int blue;

	if ((red = light->red * SHINE_CONST * shine / (dist * dist * 100)) > 255)
		red = 255;
	if ((green = light->green * SHINE_CONST * shine / (dist * dist * 100)) > 255)
		green = 255;
	if ((blue = light->blue * SHINE_CONST * shine / (dist * dist * 100)) > 255)
		blue = 255;
	return (blue + green * 256 + red * 256 * 256);
}

int	get_shine(t_intersect *intersect, t_object *objects, t_light *lights)
{
	t_coor reflect;
	double dist;
	int col;
	int tempcol;
	int i;

	col = 0;
	i = 0;
	while (lights[i].red != -1)
	{
		if (path_to_light(intersect->intersect, objects, lights + i))
		{
			get_reflection(&reflect, &(intersect->vector), intersect);
			dist = get_line_point_distance(&reflect, &(intersect->intersect), lights + i);
			tempcol = dist_to_col(dist, lights + i, intersect->object->shine);
			col = colour_sum(col, tempcol);
		}
		++i;
	}
	return (col);
}
