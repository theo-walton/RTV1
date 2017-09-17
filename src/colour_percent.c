/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 19:21:45 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 19:21:45 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	colour_percent(int col, double percent)
{
	int red;
	int green;
	int blue;

	blue = col % 256;
	col /= 256;
	green = col % 256;
	col /= 256;
	red = col % 256;
	red = (int)((double)red * percent / 100);
	green = (int)((double)green * percent / 100);
	blue = (int)((double)blue * percent / 100);
	return (blue + green * 256 + red * 256 * 256);
}
