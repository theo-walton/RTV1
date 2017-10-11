/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_of_cylinder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 23:54:10 by twalton           #+#    #+#             */
/*   Updated: 2017/09/18 23:54:10 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_normal_of_cylinder(t_coor *normal, t_intersect *intersect)
{
	t_cylinder *cylinder;
	t_coor temp;
	double dist;

	cylinder = intersect->object->type_info;
	coor_diff(&temp, intersect->intersect, cylinder->point);
	dist = dot_product(temp, cylinder->vector);
	temp.x = cylinder->point.x + cylinder->vector.x * dist;
	temp.y = cylinder->point.y + cylinder->vector.y * dist;
	temp.z = cylinder->point.z + cylinder->vector.z * dist;
	coor_diff(normal, temp, intersect->intersect);
}
