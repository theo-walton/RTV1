/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 21:10:55 by twalton           #+#    #+#             */
/*   Updated: 2017/09/28 21:10:55 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char	*go_to_next_light(char *str)
{
	return (ft_strchr(str, '>') + 1);
}

static int	light_amount(char *str)
{
	str = ft_strchr(str, '$') + 1;
	return (ft_atoi(str));
}

t_light	*create_lights(char *str)
{
	t_light *lights;
	int total_lights;

	total_lights = light_amount(str);
	lights = malloc(sizeof(t_light) * (total_lights + 1));
	lights[total_lights].red = -1;
	while (total_lights)
	{
		str = go_to_next_light(str);
		parse_light(str, lights + total_lights - 1);
		--total_lights;
	}
	return (lights);
}
