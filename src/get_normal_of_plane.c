/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_of_plane.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 22:54:40 by twalton           #+#    #+#             */
/*   Updated: 2017/09/16 22:54:40 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_normal_of_plane(t_coor *normal, t_intersect *intersect)
{
	t_plane *plane;

	plane = intersect->object->type_info;
	normal->x = plane->normal.x;
	normal->y = plane->normal.y;
	normal->z = plane->normal.z;
}
