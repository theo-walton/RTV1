/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_pixel_extrapolation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:54:08 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 08:46:36 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	extrapolate_type2(int *image, int i)
{
	if (i / X_DIM != 0)
	{
		if (i / X_DIM != Y_DIM - 1)
			image[i] = colour_merge(image[i - X_DIM], image[i + X_DIM]);
		else
			image[i] = image[i - X_DIM];
	}
	else
		image[i] = image[i + X_DIM];
}

static void	extrapolate_type1(int *image, int i)
{
	if (i % X_DIM != 0)
	{
		if (i % X_DIM != X_DIM - 1)
			image[i] = colour_merge(image[i - 1], image[i + 1]);
		else
			image[i] = image[i - 1];
	}
	else
		image[i] = image[i + 1];
}

void		apply_pixel_extrapolation(int *image)
{
	int i;

	i = 0;
	while (i < X_DIM * Y_DIM)
	{
		if (image[i] == -1 && (i / X_DIM) % 2 == 0)
			extrapolate_type1(image, i);
		++i;
	}
	i = 0;
	while (i < X_DIM * Y_DIM)
	{
		if (image[i] == -1)
			extrapolate_type2(image, i);
		++i;
	}
}
