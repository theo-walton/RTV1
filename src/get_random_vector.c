/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_random_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 21:42:16 by twalton           #+#    #+#             */
/*   Updated: 2017/09/21 21:42:16 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_random_vector(t_coor *result, t_intersect *intersect)
{
	double angle1;
	double angle2;
	t_coor normal;

	get_normal_to_intersect(&normal, intersect);
	angle1 = 2 * M_PI * rand_fct();
	angle2 = acos(1 - 2 * rand_fct());
	result->x = sin(angle1) * sin(angle2);
	result->y = sin(angle1) * cos(angle2);
	result->z = sin(angle2);
	if (dot_product(*result, normal) < 0)
	{
		result->x = -result->x;
		result->y = -result->y;
		result->z = -result->z;
	}
}
