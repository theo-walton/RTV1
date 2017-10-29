/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 21:05:21 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 08:55:27 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	get_point(char *str, char type)
{
	if (type == 'X')
		str = strstrexit(str, "xpoint:") + 7;
	if (type == 'Y')
		str = strstrexit(str, "ypoint:") + 7;
	if (type == 'Z')
		str = strstrexit(str, "zpoint:") + 7;
	return (ft_atoi(str));
}

static int	get_vector(char *str, char type)
{
	if (type == 'X')
		str = strstrexit(str, "xvector:") + 8;
	if (type == 'Y')
		str = strstrexit(str, "yvector:") + 8;
	if (type == 'Z')
		str = strstrexit(str, "zvector:") + 8;
	return (ft_atoi(str));
}

static int	get_radius(char *str)
{
	str = strstrexit(str, "radius:") + 7;
	return (ft_atoi(str));
}

static void	normalize(t_coor *coor)
{
	double size;

	size = sqrt(dot_product(*coor, *coor));
	coor->x /= size;
	coor->y /= size;
	coor->z /= size;
}

void		get_cylinder_info(char *str, t_object *object)
{
	t_cylinder *cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	cylinder->point.x = (double)get_point(str, 'X');
	cylinder->point.y = (double)get_point(str, 'Y');
	cylinder->point.z = (double)get_point(str, 'Z');
	cylinder->vector.x = (double)get_vector(str, 'X');
	cylinder->vector.y = (double)get_vector(str, 'Y');
	cylinder->vector.z = (double)get_vector(str, 'Z');
	cylinder->radius = (double)get_radius(str);
	normalize(&(cylinder->vector));
	object->type_info = cylinder;
	object->type = CYLINDER;
}
