/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_intersections.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:49:42 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:01:28 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	get_intersect(t_coor *intersect, double dist, t_coor *point,
				t_coor *vector)
{
	intersect->x = point->x + dist * vector->x;
	intersect->y = point->y + dist * vector->y;
	intersect->z = point->z + dist * vector->z;
}

static int	fill_intersect(double consts[], t_intersect *intersect,
				t_coor *point, t_coor *vector)
{
	if (consts[0] == INFIN || consts[0] <= 0)
		intersect[0].object = NULL;
	else
		get_intersect(&(intersect[0].intersect), consts[0], point, vector);
	if (consts[1] == INFIN || consts[1] <= 0)
		intersect[1].object = NULL;
	else
		get_intersect(&(intersect[1].intersect), consts[1], point, vector);
	if ((consts[0] == INFIN || consts[0] <= 0) &&
	(consts[1] == INFIN || consts[1] <= 0))
	{
		return (0);
	}
	return (1);
}

int			get_cylinder_intersections(t_intersect *intersect, t_object *object,
							t_coor *point, t_coor *vector)
{
	t_cylinder	*cylinder;
	t_coor		vect1;
	t_coor		vect2;
	t_coor		vect3;
	double		consts[4];

	intersect[0].object = object;
	intersect[1].object = object;
	cylinder = object->type_info;
	coor_diff(&vect1, cylinder->vector, cylinder->point);
	coor_diff(&vect2, *point, cylinder->point);
	cross_product(&vect3, vect2, vect1);
	cross_product(&vect2, *vector, vect1);
	consts[0] = dot_product(vect1, vect1);
	consts[1] = dot_product(vect2, vect2);
	consts[2] = 2 * dot_product(vect2, vect3);
	consts[3] = dot_product(vect3, vect3) - cylinder->radius *
			cylinder->radius * consts[0];
	second_order_solver(consts, consts[1], consts[2], consts[3]);
	return (fill_intersect(consts, intersect, point, vector));
}
