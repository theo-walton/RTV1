/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:10:42 by twalton           #+#    #+#             */
/*   Updated: 2017/09/20 21:10:42 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	col_to_int(t_colour col)
{
	int red;
	int green;
	int blue;

	if ((red = col.red) > 255)
		red = 255;
	if ((green = col.green) > 255)
                green = 255;
	if ((blue = col.blue) > 255)
                blue = 255;
	return (blue + green * 256 + red * 256 * 256);
}
