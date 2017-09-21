/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_point_distance.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:28:24 by twalton           #+#    #+#             */
/*   Updated: 2017/09/18 15:28:24 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	get_line_point_distance(t_coor *reflect, t_coor *point1, t_light *light)
{
	t_coor point2;
	t_coor temp1;
	t_coor temp2;
	t_coor temp3;
	t_coor point0;

	point0.x = light->x;
	point0.y = light->y;
	point0.z = light->z;
	coor_diff(&point2, *point1, *reflect);
	coor_diff(&temp1, point0, *point1);
	coor_diff(&temp2, point0, point2);
	cross_product(&temp3, temp1, temp2);
	coor_diff(&temp1, point2, *point1);
	return (sqrt(dot_product(temp3, temp3) / dot_product(temp1, temp1)));
}
