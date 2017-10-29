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

	info.layout = ft_dirty_read(0, 100000);
	info.objects = create_objects(info.layout);
	info.lights = create_lights(info.layout);
	info.screen = create_screen(info.layout);
	info.mlx = mlx_init();
	info.im = create_scene(&info);
	info.win = mlx_new_window(info.mlx, X_DIM, Y_DIM, "");
	set_hooks(&info);
	mlx_loop(info.mlx);
}
