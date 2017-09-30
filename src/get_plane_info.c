/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:39:18 by twalton           #+#    #+#             */
/*   Updated: 2017/09/28 20:39:18 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	get_norm(char *str, char type)
{
	if (type == 'X')
		str = ft_strstr(str, "xnormal:") + 8;
	else if (type == 'Y')
		str = ft_strstr(str, "ynormal:") + 8;
	else if (type == 'Z')
		str = ft_strstr(str, "znormal:") + 8;
	return (ft_atoi(str));
}

static int	get_point(char *str, char type)
{
	if (type == 'X')
		str = ft_strstr(str, "xpoint:") + 7;
	else if (type == 'Y')
		str = ft_strstr(str, "ypoint:") + 7;
	else if	(type == 'Z')
		str = ft_strstr(str, "zpoint:") + 7;
	return (ft_atoi(str));
}

static void	make_normal_unit_length(t_plane *plane)
{
	double dot;

	dot = sqrt(dot_product(plane->normal, plane->normal));
	plane->normal.x /= dot;
	plane->normal.y /= dot;
	plane->normal.z /= dot;
}

void	get_plane_info(char *str, t_object *object)
{
	t_plane *plane;

	plane = malloc(sizeof(t_plane));
	plane->normal.x = (double)get_norm(str, 'X');
	plane->normal.y = (double)get_norm(str, 'Y');
	plane->normal.z = (double)get_norm(str, 'Z');
	plane->point.x = (double)get_point(str, 'X');
	plane->point.y = (double)get_point(str, 'Y');
	plane->point.z = (double)get_point(str, 'Z');
	make_normal_unit_length(plane);
	object->type_info = plane;
	object->type = PLANE;
}
