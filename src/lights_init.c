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

	lights = malloc(sizeof(t_light) * 3);
	lights[0].x = 100;
	lights[0].y = 000;
	lights[0].z = -10000;
	lights[0].red = 100000;
	lights[0].blue = 50000;
	lights[0].green = 100000;
        lights[1].x = -900;
        lights[1].y = 400;
        lights[1].z = 0;
        lights[1].red = 10000;
        lights[1].blue = 10000;
        lights[1].green = 10000;
	lights[2].red = -1;
	return (lights);
}
