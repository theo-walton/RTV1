/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_dist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:01:03 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 08:59:23 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	calc_a(t_coor *vector, t_cylinder *cylinder)
{
	t_coor temp;
	double dot;

	dot = dot_product(*vector, cylinder->vector);
	temp.x = dot * cylinder->vector.x;
	temp.y = dot * cylinder->vector.y;
	temp.z = dot * cylinder->vector.z;
	coor_diff(&temp, *vector, temp);
	return (dot_product(temp, temp));
}

static double	calc_b(t_coor *point_diff, t_coor *vector, t_cylinder *cylinder)
{
	t_coor temp1;
	t_coor temp2;
	double dot;

	dot = dot_product(*point_diff, cylinder->vector);
	temp1.x = dot * cylinder->vector.x;
	temp1.y = dot * cylinder->vector.y;
	temp1.z = dot * cylinder->vector.z;
	coor_diff(&temp1, *point_diff, temp1);
	dot = dot_product(*vector, cylinder->vector);
	temp2.x = dot * cylinder->vector.x;
	temp2.y = dot * cylinder->vector.y;
	temp2.z = dot * cylinder->vector.z;
	coor_diff(&temp2, *vector, temp2);
	return (2 * (dot_product(temp2, temp1)));
}

static double	calc_c(t_coor *point_diff, t_cylinder *cylinder)
{
	t_coor temp;
	double dot;

	dot = dot_product(*point_diff, cylinder->vector);
	temp.x = dot * cylinder->vector.x;
	temp.y = dot * cylinder->vector.y;
	temp.z = dot * cylinder->vector.z;
	coor_diff(&temp, *point_diff, temp);
	dot = dot_product(temp, temp);
	return (dot - (cylinder->radius * cylinder->radius));
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

double			get_cylinder_dist(t_coor *point, t_coor *vector,
						t_object *object)
{
	t_cylinder	*cylinder;
	t_coor		point_diff;
	double		coefficients[3];
	double		result[2];

	cylinder = object->type_info;
	coor_diff(&point_diff, *point, cylinder->point);
	coefficients[0] = calc_a(vector, cylinder);
	coefficients[1] = calc_b(&point_diff, vector, cylinder);
	coefficients[2] = calc_c(&point_diff, cylinder);
	second_order_solver(result, coefficients[0],
				coefficients[1], coefficients[2]);
	return (closest_distance(result[0], result[1]));
}
