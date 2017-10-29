/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_of_cone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 21:36:10 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:33:28 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_normal_of_cone(t_coor *normal, t_intersect *intersect)
{
	t_cone	*cone;
	double	side_len;
	t_coor	temp;

	cone = intersect->object->type_info;
	coor_diff(&temp, intersect->intersect, cone->point);
	side_len = sqrt(dot_product(temp, temp));
	side_len /= cos(cone->angle);
	if (dot_product(temp, cone->vector) < 0)
		side_len = -side_len;
	temp.x = cone->point.x + side_len * cone->vector.x;
	temp.y = cone->point.y + side_len * cone->vector.y;
	temp.z = cone->point.z + side_len * cone->vector.z;
	coor_diff(normal, intersect->intersect, temp);
}
