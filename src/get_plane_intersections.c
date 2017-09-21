/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_intersections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 22:33:30 by twalton           #+#    #+#             */
/*   Updated: 2017/09/16 22:33:30 by twalton          ###   ########.fr       */
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

int	get_plane_intersections(t_intersect *intersect, t_object *object, t_coor *point, t_coor *vector)
{
	t_plane *plane;
	double dist;
	t_coor temp;

	plane = object->type_info;
	coor_diff(&temp, plane->point, *point);
	dist = dot_product(*vector, plane->normal);
	if (dist == 0)
		return (nullify_intersect(intersect, 0));
	dist = dot_product(temp, plane->normal) / dist;
	if (dist <= 1)
		return (nullify_intersect(intersect, 0));
	dist -= 1;
	intersect[0].object = object;
	intersect[1].object = NULL;
	get_intersect(&(intersect[0].intersect), dist, point, vector);
	return (1);
}
