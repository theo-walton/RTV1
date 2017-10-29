/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:54:15 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 08:54:17 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	calculate_a(t_coor *vector, t_cone *cone)
{
	double dot;
	double cos_sq;

	dot = dot_product(*vector, cone->vector);
	dot *= dot;
	cos_sq = cos(cone->angle);
	cos_sq *= cos_sq;
	return (dot - cos_sq);
}

static double	calculate_b(t_coor *vector, t_coor point_diff, t_cone *cone)
{
	double dot1;
	double dot2;
	double dot3;
	double cos_sq;

	dot1 = dot_product(*vector, cone->vector);
	dot2 = dot_product(point_diff, cone->vector);
	dot3 = dot_product(*vector, point_diff);
	cos_sq = cos(cone->angle);
	cos_sq *= cos_sq;
	return (2 * ((dot1 * dot2) - (dot3 * cos_sq)));
}

static double	calculate_c(t_coor point_diff, t_cone *cone)
{
	double dot1;
	double dot2;
	double cos_sq;

	dot1 = dot_product(point_diff, cone->vector);
	dot2 = dot_product(point_diff, point_diff);
	cos_sq = cos(cone->angle);
	cos_sq *= cos_sq;
	return (dot1 * dot1 - dot2 * cos_sq);
}

static double	closest_distance(double dist1, double dist2)
{
	if (dist1 < dist2)
	{
		if (dist1 > 1)
			return (dist1);
		if (dist2 > 1)
			return (dist2);
		return (INFIN);
	}
	if (dist2 > 1)
		return (dist2);
	if (dist1 > 1)
		return (dist1);
	return (INFIN);
}

double			get_cone_dist(t_coor *point, t_coor *vector, t_object *object)
{
	t_cone *cone;
	t_coor point_diff;
	double coeff[3];
	double result[2];
	double ret;

	cone = object->type_info;
	coor_diff(&point_diff, *point, cone->point);
	coeff[0] = calculate_a(vector, cone);
	coeff[1] = calculate_b(vector, point_diff, cone);
	coeff[2] = calculate_c(point_diff, cone);
	second_order_solver(result, coeff[0], coeff[1], coeff[2]);
	ret = closest_distance(result[0], result[1]);
	return (ret);
}
