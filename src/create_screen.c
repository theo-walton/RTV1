/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:14:25 by twalton           #+#    #+#             */
/*   Updated: 2017/09/09 14:14:25 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	vect_init(t_coor *result, t_coor *coor1, t_coor *coor2)
{
	double quotient;

	quotient = 0;
	coor_diff(result, *coor1, *coor2);
	quotient += result->x * result->x;
	quotient += result->y * result->y;
	quotient += result->z * result->z;
	quotient = sqrt(quotient);
	result->x /= quotient;
	result->y /= quotient;
	result->z /= quotient;
}

static void	initialize_vectors(t_screen *new)
{
	int i;
	int j;
	t_coor veiw_point;

	veiw_point.x = 0;
	veiw_point.y = 0;
	veiw_point.z = -VEIW_DIST;
	i = 0;
	j = 0;
	while (i < X_DIM)
	{
		while (j < Y_DIM)
		{
			vect_init(&new->vectors[i + X_DIM * j],
			&new->coorarr[i + X_DIM * j], &veiw_point);
			++j;
		}
		j = 0;
		++i;
	}
}

static void	initialize_coordinates(t_screen *new)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < X_DIM)
	{
		while (j < Y_DIM)
		{
			new->coorarr[i + X_DIM * j].x = i - X_DIM / 2;
			new->coorarr[i + X_DIM * j].y = Y_DIM / 2 - j;
			new->coorarr[i + X_DIM * j].z = 0;
			++j;
		}
		j = 0;
		++i;
	}
}

t_screen	*create_screen(void)
{
	t_screen *new;

	new = malloc(sizeof(t_screen));
	new->coorarr = malloc(sizeof(t_coor) * X_DIM * Y_DIM);
	new->vectors = malloc(sizeof(t_coor) * X_DIM * Y_DIM);
	initialize_coordinates(new);
	initialize_vectors(new);
	return (new);
}
