/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_basic_screen_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 16:19:29 by twalton           #+#    #+#             */
/*   Updated: 2017/09/10 16:19:29 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_basic_screen_image(t_screen *screen, int *image, t_object *objects, t_light *lights)
{
	int i;
	t_intersect *intersect;

	i = 0;
	while (i < X_DIM * Y_DIM)
	{
		if (1)//(i % X_DIM) % 2 == 0 && (i / X_DIM) % 2 == 0)
		{
			intersect = get_first_object_ray_hits(screen->coorarr + i, screen->vectors + i, objects);
			if (intersect)
				image[i] = find_colour_of_intersect(intersect, objects, lights);
			else
			{
				image[i] = 0x222222;
				free(intersect);
			}
		}
		else
			image[i] = -1;
		++i;
	}
	apply_pixel_extrapolation(image);
}
