/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_modifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:02:55 by twalton           #+#    #+#             */
/*   Updated: 2017/09/14 20:02:55 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	get_light_modifier(t_intersect *intersect, t_light *light)
{
	double dot;
	t_coor normal;
	t_coor light_vector;

	light_vector.x = light->x - intersect->intersect.x;
	light_vector.y = light->y - intersect->intersect.y;
	light_vector.z = light->z - intersect->intersect.z;
	get_normal_to_intersect(&normal, intersect);
	dot = dot_product(normal, light_vector);
	return (fabs(dot / (vector_size(normal) * vector_size(light_vector))));
}
