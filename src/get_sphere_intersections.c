/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 19:59:18 by twalton           #+#    #+#             */
/*   Updated: 2017/09/03 19:59:18 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	get_intersect(t_coor *intersect, double dist, t_coor *point, t_coor *vector)
{
	intersect->x = point->x + dist * vector->x;
	intersect->y = point->y + dist * vector->y;
	intersect->z = point->z + dist * vector->z;
}

static int	nullify_intersect(t_intersect *intersect, int ret)
{
	intersect[0].object = NULL;
	intersect[1].object = NULL;
	return (ret);
}

int	get_sphere_intersections(t_intersect *intersect, t_object *object, t_coor *point, t_coor *vector)
{
	t_sphere *sphere;
	t_coor temp;
	double d[2];
	double disc;

	sphere = object->type_info;
	coor_diff(&temp, *point, sphere->center);
	d[0] = dot_product(*vector, temp); 
	disc = d[0] * d[0] - dot_product(temp, temp) + sphere->radius * sphere->radius;
	if (disc < 0)
		return (nullify_intersect(intersect, 0));
	if (disc == 0)
	{
		d[1] = -d[0];
		if (d[1] <= 0)
			return (nullify_intersect(intersect, 0));
		intersect[0].object = object;
		intersect[1].object = NULL;
		get_intersect(&(intersect[0].intersect), d[1], point, vector);
		return (1);
	}
	disc = sqrt(disc);
	d[1] = -d[0] - disc;
	d[0] = -d[0] + disc;
	intersect[0].object = object;
	intersect[1].object = object;
	if (d[0] <= 1 && d[1] <= 1)
		return (nullify_intersect(intersect, 0));
	if (d[0] > 0)
		get_intersect(&(intersect[0].intersect), d[0], point, vector);
	else
		intersect[0].object = NULL;
	if (d[1] > 0)
		get_intersect(&(intersect[1].intersect), d[1], point, vector);
	else
		intersect[1].object = NULL;
	return (1);
}
