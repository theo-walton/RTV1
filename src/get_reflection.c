/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 20:08:55 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 20:08:55 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_reflection(t_coor *reflection, t_coor *vector, t_intersect *intersect)
{
	t_coor normal;
	double size;

	get_normal_to_intersect(&normal, intersect);
	size = vector_size(normal);
	normal.x /= size;
	normal.y /= size;
	normal.z /= size;
	size = 2 * dot_product(*vector, normal);
	normal.x *= size;
	normal.y *= size;
	normal.z *= size;
	coor_diff(reflection, *vector, normal);
}
