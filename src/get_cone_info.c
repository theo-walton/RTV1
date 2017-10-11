/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 20:35:45 by twalton           #+#    #+#             */
/*   Updated: 2017/10/10 20:35:45 by twalton          ###   ########.fr       */
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

static int	get_vector(char *str, char type)
{
	if (type == 'X')
		str = ft_strstr(str, "xvector:") + 8;
	if (type == 'Y')
		str = ft_strstr(str, "yvector:") + 8;
	if (type == 'Z')
		str = ft_strstr(str, "zvector:") + 8;
	return (ft_atoi(str));
}

static double	get_angle(char *str)
{
	double angle;

	str = ft_strstr(str, "angle:") + 6;
	angle = (double)ft_atoi(str);
	return (angle * M_PI / 180);
}

static void	normalize(t_coor *coor)
{
	double size;

	size = sqrt(dot_product(*coor, *coor));
	coor->x /= size;
	coor->y /= size;
	coor->z /= size;
}

void	get_cone_info(char *str, t_object *object)
{
	t_cone *cone;

	cone = malloc(sizeof(t_cone));
	cone->point.x = (double)get_point(str, 'X');
	cone->point.y = (double)get_point(str, 'Y');
	cone->point.z = (double)get_point(str, 'Z');
	cone->vector.x = (double)get_vector(str, 'X');
	cone->vector.y = (double)get_vector(str, 'Y');
	cone->vector.z = (double)get_vector(str, 'Z');
	cone->angle = get_angle(str);
	normalize(&(cone->vector));
	object->type_info = cone;
	object->type = CONE;
}
