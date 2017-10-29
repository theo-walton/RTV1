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

void	colour_sum(t_colour *result, t_colour col1, t_colour col2)
{
	if (isnan(col1.red))
		col1.red = 0;
	if (isnan(col1.green))
		col1.green = 0;
	if (isnan(col1.blue))
		col1.blue = 0;
	if (isnan(col2.red))
		col2.red = 0;
	if (isnan(col2.green))
		col2.green = 0;
	if (isnan(col2.blue))
		col2.blue = 0;
	result->red = col1.red + col2.red;
	result->green = col1.green + col2.green;
	result->blue = col1.blue + col2.blue;
}
