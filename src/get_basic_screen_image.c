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
	t_colour col;

	i = 0;
	while (i < X_DIM * Y_DIM)
	{
		intersect = get_first_object_ray_hits(screen->coorarr + i, screen->vectors + i, objects);
		if (intersect)
		{
			find_colour_of_intersect(&col, intersect, objects, lights);
//			if (col.red > 100)
//				printf(" | %f, %f, %f |", col.red, col.green, col.blue);
			image[i] = col_to_int(col);
			get_reflect_col(NULL, NULL, NULL, NULL);
		}
		else
		{
			image[i] = 0x222222;
			free(intersect);
		}
		++i;
	}
}
