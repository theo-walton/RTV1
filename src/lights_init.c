/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 00:06:53 by twalton           #+#    #+#             */
/*   Updated: 2017/09/11 00:06:53 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light	*lights_init(void)
{
	t_light *lights;

	lights = malloc(sizeof(t_light) * 2);
	lights[0].x = 0;
	lights[0].y = 0;
	lights[0].z = 0;
	lights[0].red = 1000;
	lights[0].blue = 1000;
	lights[0].green = 1000;
	lights[1].red = -1;
	return (lights);
}
