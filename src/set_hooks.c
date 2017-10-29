/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 08:19:50 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:45:05 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	expose(t_info *info)
{
	mlx_clear_window(info->mlx, info->win);
	mlx_put_image_to_window(info->mlx, info->win, info->im->ptr, 0, 0);
	return (1);
}

static int	exit_hook(t_info *info)
{
	(void)info;
	exit(1);
	return (1);
}

static int	key_press_hook(int keynum, t_info *info)
{
	(void)info;
	if (keynum == KEY_ESC)
		exit(1);
	return (1);
}

void		set_hooks(t_info *info)
{
	mlx_expose_hook(info->win, expose, info);
	mlx_hook(info->win, 17, 0, exit_hook, info);
	mlx_hook(info->win, 2, 0, key_press_hook, info);
}
