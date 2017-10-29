/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 21:30:45 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:34:27 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	get_plane_dist(t_coor *point, t_coor *vector, t_object *object)
{
	t_plane	*plane;
	double	dist;
	t_coor	temp;

	plane = object->type_info;
	coor_diff(&temp, plane->point, *point);
	dist = dot_product(*vector, plane->normal);
	if (dist == 0)
		return (INFIN);
	dist = dot_product(temp, plane->normal) / dist;
	if (dist <= 1)
		return (INFIN);
	return (dist);
}
