/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_sum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 19:25:39 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 19:25:39 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	bias_sum(double a, double b)
{
	return (hypot(a, b));
}

int	colour_sum(int col1, int col2)
{
	int red;
	int green;
	int blue;

	if ((blue = bias_sum(col1 % 256, col2 % 256)) > 255)
		blue = 255;
	col1 /= 256;
	col2 /= 256;
	if ((green = bias_sum(col1 % 256, col2 % 256)) > 255)
		green = 255;
	col1 /= 256;
	col2 /= 256;
	if ((red = bias_sum(col1 % 256, col2 % 256)) > 255)
		red = 255;
	return (blue + green * 256 + red * 256 * 256);
}
