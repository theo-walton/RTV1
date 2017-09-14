/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:12:08 by twalton           #+#    #+#             */
/*   Updated: 2017/09/02 17:12:08 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	main(void)
{
	t_info info;

	info.objects = objects_init();
	info.lights = lights_init();
	info.screen = create_screen();
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, X_DIM, Y_DIM, "");
	draw_objects(&info);
	mlx_loop(info.mlx);
}
