/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 21:13:30 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:39:15 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	closest_distance(double dist1, double dist2)
{
	if (dist1 < dist2)
	{
		if (dist1 > 1)
			return (dist1);
		if (dist2 > 1)
			return (dist2);
		return (INFIN);
	}
	if (dist2 > 1)
		return (dist2);
	if (dist1 > 1)
		return (dist1);
	return (INFIN);
}

double			get_sphere_dist(t_coor *point, t_coor *vector, t_object *object)
{
	t_sphere	*sphere;
	t_coor		temp;
	double		d[2];
	double		disc;

	sphere = object->type_info;
	coor_diff(&temp, *point, sphere->center);
	d[0] = dot_product(*vector, temp);
	disc = d[0] * d[0] - dot_product(temp, temp) +
			sphere->radius * sphere->radius;
	if (disc < 0)
		return (INFIN);
	disc = sqrt(disc);
	d[1] = -d[0] - disc;
	d[0] = -d[0] + disc;
	return (closest_distance(d[0], d[1]));
}
