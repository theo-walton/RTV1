/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 00:24:05 by twalton           #+#    #+#             */
/*   Updated: 2017/09/11 00:24:05 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw_objects(t_info *info)
{
	t_image im;

	im.ptr = mlx_new_image(info->mlx, X_DIM, Y_DIM);
	im.im = (int*)mlx_get_data_addr(im.ptr, &im.bpp, &im.line_sz, &im.end);
	get_basic_screen_image(info->screen, im.im, info->objects, info->lights);
	mlx_clear_window(info->mlx, info->win);
	mlx_put_image_to_window(info->mlx, info->win, im.ptr, 0, 0);
	mlx_destroy_image(info->mlx, im.ptr);
}
