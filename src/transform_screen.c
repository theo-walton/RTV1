/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:16:18 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:47:37 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		shift_screen(t_screen *screen, t_coor center)
{
	int i;

	i = 0;
	while (i < X_DIM * Y_DIM)
	{
		screen->coorarr[i].x += center.x;
		screen->coorarr[i].y += center.y;
		screen->coorarr[i].z += center.z;
		++i;
	}
}

static void		x_rotation(t_coor *vector, double rot_amount)
{
	double old1;
	double old2;

	old1 = vector->y;
	old2 = vector->z;
	vector->y = old1 * cos(rot_amount) + old2 * sin(rot_amount);
	vector->z = old2 * cos(rot_amount) - old1 * sin(rot_amount);
}

static void		y_rotation(t_coor *vector, double rot_amount)
{
	double old1;
	double old2;

	old1 = vector->x;
	old2 = vector->z;
	vector->x = old1 * cos(rot_amount) + old2 * sin(rot_amount);
	vector->z = old2 * cos(rot_amount) - old1 * sin(rot_amount);
}

static void		z_rotation(t_coor *vector, double rot_amount)
{
	double old1;
	double old2;

	old1 = vector->x;
	old2 = vector->y;
	vector->x = old1 * cos(rot_amount) + old2 * sin(rot_amount);
	vector->y = old2 * cos(rot_amount) - old1 * sin(rot_amount);
}

void			transform_screen(t_screen *screen, t_coor center,
				t_coor direction)
{
	int i;

	i = 0;
	shift_screen(screen, center);
	while (i < X_DIM * Y_DIM)
	{
		x_rotation(&screen->vectors[i], direction.x);
		y_rotation(&screen->vectors[i], direction.y);
		z_rotation(&screen->vectors[i], direction.z);
		++i;
	}
}
