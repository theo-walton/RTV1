/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:54:15 by twalton           #+#    #+#             */
/*   Updated: 2017/10/10 17:54:15 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	calculate_a(t_coor *vector, t_cone *cone)
{
	t_coor temp;
	double dot1;
	double dot2;

	dot2 = dot_product(*vector, cone->vector);
	temp.x = dot2 * cone->vector.x;
	temp.y = dot2 * cone->vector.y;
	temp.z = dot2 * cone->vector.z;
	coor_diff(&temp, *vector, temp);
	dot1 = cos(dot_product(temp, temp) * cone->angle);
	dot1 *= dot1;
	dot2 = sin(cone->angle * dot2 * dot2);
	dot2 *= dot2;
	return (dot1 - dot2);
}

static double	calculate_b(t_coor *vector, t_coor point_diff, t_cone *cone)
{
	t_coor temp1;
	t_coor temp2;
	double num1;
	double num2;

	num1 = sin(cone->angle * dot_product(*vector, cone->vector) *
		 dot_product(point_diff, cone->vector));
	num1 *= 2 * num1;
	num2 = dot_product(point_diff, cone->vector);
	temp1.x = num2 * cone->vector.x;
	temp1.y = num2 * cone->vector.y;
	temp1.z = num2 * cone->vector.z;
	coor_diff(&temp1, point_diff, temp1);
	num2 = dot_product(*vector, cone->vector);
	temp2.x = num2 * cone->vector.x;
	temp2.y = num2 * cone->vector.y;
	temp2.z = num2 * cone->vector.z;
	coor_diff(&temp2, *vector, temp2);
	num2 = cos(dot_product(temp1, temp2) * cone->angle);
	num2 *= 2 * num2;
	return (num2 - num1);
}

static double	calculate_c(t_coor *vector, t_coor point_diff, t_cone *cone)
{
	t_coor temp1;
	t_coor temp2;
	double num1;
	double num2;

	num1 = dot_product(point_diff, cone->vector);
	temp1.x = num1 * cone->vector.x;
	temp1.y = num1 * cone->vector.y;
	temp1.z = num1 * cone->vector.z;
	coor_diff(&temp1, point_diff, temp1);
	num2 = cos(dot_product(temp1, temp1) * cone->angle);
	num2 *= num2;
	num1 = sin(cone->angle * num1 * num1);
	num1 *= num1;
	return (num2 - num1);
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

#include <stdio.h>

double	get_cone_dist(t_coor *point, t_coor *vector, t_object *object)
{
	t_cone *cone;
	t_coor point_diff;
	double coeff[3];
	double result[2];

	cone = object->type_info;

	printf("%lf, %lf, %lf\n", cone->angle, cone->point.z, cone->vector.x);

	coor_diff(&point_diff, *point, cone->point);
	coeff[0] = calculate_a(vector, cone);
	coeff[1] = calculate_b(vector, point_diff, cone);
	coeff[2] = calculate_c(vector, point_diff, cone);
	second_order_solver(result, coeff[0], coeff[1], coeff[2]);
	return (closest_distance(result[0], result[1]));
}
