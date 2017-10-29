/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 08:12:36 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 08:12:36 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_image	*create_scene(t_info *info)
{
	t_image *i;

	i = malloc(sizeof(t_image));
	i->ptr = mlx_new_image(info->mlx, X_DIM, Y_DIM);
	i->im = (int*)mlx_get_data_addr(i->ptr, &i->bpp, &i->line_sz, &i->end);
	get_basic_screen_image(info->screen, i->im, info->objects, info->lights);
	return (i);
}
