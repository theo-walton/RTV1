/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_of_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 21:01:58 by twalton           #+#    #+#             */
/*   Updated: 2017/09/14 21:01:58 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_normal_of_sphere(t_coor *normal, t_intersect *intersect)
{
	t_sphere *sphere;

	sphere = intersect->object->type_info;
	normal->x = sphere->center.x - intersect->intersect.x;
	normal->y = sphere->center.y - intersect->intersect.y;
	normal->z = sphere->center.z - intersect->intersect.z;
}
