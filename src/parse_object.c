/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 18:48:44 by twalton           #+#    #+#             */
/*   Updated: 2017/09/28 18:48:44 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	get_shine_num(char *str)
{
	str = ft_strstr(str, "shine:") + 6;
	return (ft_atoi(str));
}

static int	get_col(char *str, char type)
{
	if (type == 'R')
		str = ft_strstr(str, "red:") + 4;
	else if (type == 'G')
		str = ft_strstr(str, "green:") + 6;
	else if (type == 'B')
		str = ft_strstr(str, "blue:") +	5;
	return (ft_atoi(str));
}

static int	object_type(char *str)
{
	if (!ft_strncmp(str, "sphere", 6))
		return (SPHERE);
	if (!ft_strncmp(str, "plane", 5))
		return (PLANE);
//	if (!ft_strncmp(str, "cylinder", 8))
//		return (CYLINDER);
//	if (!ft_strncmp(str, "cone", 4))
//		return (CONE);
	return (0);
}

void	parse_object(char *str, t_object *object)
{
	int type;

	type = object_type(str);
	object->shine = (double)get_shine_num(str);
	object->red = (double)get_col(str, 'R');
	object->green = (double)get_col(str, 'G');
	object->blue = (double)get_col(str, 'B');
	str = ft_strchr(str, '.');
	if (type == SPHERE)
		get_sphere_info(str, object);
	if (type == PLANE)
		get_plane_info(str, object);
//	if (object_type == CYLINDER)
//		get_cylinder_info(str, object);
//	if (object_type == CONE)
//		get_cone_info(str, object);
}
