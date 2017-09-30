/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:19:47 by twalton           #+#    #+#             */
/*   Updated: 2017/09/28 20:19:47 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	get_radius(char *str)
{
	str = ft_strstr(str, "radius:") + 7;
	return (ft_atoi(str));
}

static int	get_x(char *str)
{
	str = ft_strstr(str, "x:") + 2;
	return (ft_atoi(str));
}

static int	get_y(char *str)
{
	str = ft_strstr(str, "y:") + 2;
	return (ft_atoi(str));
}

static int	get_z(char *str)
{
	str = ft_strstr(str, "z:") + 2;
	return (ft_atoi(str));
}

void	get_sphere_info(char *str, t_object *object)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->radius = (double)get_radius(str);
	sphere->center.x = (double)get_x(str);
	sphere->center.y = (double)get_y(str);
	sphere->center.z = (double)get_z(str);
	object->type_info = sphere;
	object->type = SPHERE;
}
