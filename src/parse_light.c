/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:45:23 by twalton           #+#    #+#             */
/*   Updated: 2017/09/28 22:45:23 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	get_point(char *str, char type)
{
	if (type == 'X')
		str = ft_strstr(str, "xpoint:") + 7;
	if (type == 'Y')
		str = ft_strstr(str, "ypoint:") + 7;
	if (type == 'Z')
		str = ft_strstr(str, "zpoint:") + 7;
	return (ft_atoi(str));
}

static int	get_col(char *str, char type)
{
	if (type == 'R')
		str = ft_strstr(str, "red:") + 4;
	if (type == 'G')
		str = ft_strstr(str, "green:") + 6;
	if (type == 'B')
		str = ft_strstr(str, "blue:") + 5;
	return (ft_atoi(str));
}

void	parse_light(char *str, t_light *light)
{
	light->x = (double)get_point(str, 'X');
	light->y = (double)get_point(str, 'Y');
	light->z = (double)get_point(str, 'Z');
	light->red = (double)get_col(str, 'R');
	light->green = (double)get_col(str, 'G');
	light->blue = (double)get_col(str, 'B');
}
