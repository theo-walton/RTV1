/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_order_solver.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 23:45:10 by twalton           #+#    #+#             */
/*   Updated: 2017/09/18 23:45:10 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	second_order_solver(double *result, double a, double b, double c)
{
	double disc;

	disc = b * b - 4 * a * c;
	if (disc < 0)
	{
		result[0] = INFIN;
		result[1] = INFIN;
		return ;
	}
	if (disc == 0)
	{
		result[0] = -b;
		result[1] = INFIN;
		return ;
	}
	disc = sqrt(disc) / (2 * a);
	result[0] = -b + disc;
	result[1] = -b - disc;
}
