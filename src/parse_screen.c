/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:36:54 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:42:47 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		get_center(char *str, char type)
{
	if (type == 'X')
		str = strstrexit(str, "xcenter:") + 8;
	if (type == 'Y')
		str = strstrexit(str, "ycenter:") + 8;
	if (type == 'Z')
		str = strstrexit(str, "zcenter:") + 8;
	return (ft_atoi(str));
}

static double	get_direction(char *str, char type)
{
	double ret;

	if (type == 'X')
		str = strstrexit(str, "xangle:") + 7;
	if (type == 'Y')
		str = strstrexit(str, "yangle:") + 7;
	if (type == 'Z')
		str = strstrexit(str, "zangle:") + 7;
	ret = (double)ft_atoi(str);
	return (ret * M_PI / 180);
}

void			parse_screen(char *str, t_coor *center, t_coor *direction)
{
	str = strstrexit(str, "screen") + 6;
	center->x = (double)get_center(str, 'X');
	center->y = -(double)get_center(str, 'Y');
	center->z = (double)get_center(str, 'Z');
	direction->x = get_direction(str, 'X');
	direction->y = get_direction(str, 'Y');
	direction->z = get_direction(str, 'Z');
}
