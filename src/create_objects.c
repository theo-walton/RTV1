/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 18:28:12 by twalton           #+#    #+#             */
/*   Updated: 2017/09/28 18:28:12 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char	*go_to_next_object(char *str)
{
	return (ft_strchr(str, '+') + 1);
}

static int	object_amount(char *str)
{
	str = ft_strchr(str, '#') + 1;
	return (ft_atoi(str));
}

t_object	*create_objects(char *str)
{
	t_object *objects;
	int total_objects;

	total_objects = object_amount(str);
	objects = malloc(sizeof(t_object) * (total_objects + 1));
	objects[total_objects].type = 0;
	while (total_objects)
	{
		str = go_to_next_object(str);
		parse_object(str, objects + total_objects - 1);
		--total_objects;
	}
	return (objects);
}
