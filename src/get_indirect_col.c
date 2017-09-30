/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indirect_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 03:01:54 by twalton           #+#    #+#             */
/*   Updated: 2017/09/21 03:01:54 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	basic_surface_col(t_colour *result, t_intersect *intersect, t_object *objects, t_light *lights)
{
	t_colour col1;
	t_colour col2;

	get_diffuse_col(result, intersect, objects, lights);
//	get_reflect_col(&col2, intersect, objects, lights);
//	colour_percent(&col2, intersect->object->shine);
//	colour_sum(&col1, col1, col2);
//	get_shine(&col2, intersect, objects, lights);
	free(intersect);
//	colour_sum(result, col1, col2);
}

static void	get_random_ray_colour(t_colour *result, t_intersect *intersect, t_object *objects, t_light *lights)
{
	t_coor vector;
	t_intersect *new;

	get_random_vector(&vector, intersect);
	new = get_first_object_ray_hits(&(intersect->intersect), &vector, objects);
	basic_surface_col(result, new, objects, lights);
}

void	get_indirect_col(t_colour *result, t_intersect *intersect, t_object *objects, t_light *lights)
{
	int i;
	t_colour col;
	static int tog;

	i = 0;
	zero_colour(result);
	if (tog)
		return ;
	++tog;
	while (i < MONTE_CARLO_MAX_RAYS)
	{
		get_random_ray_colour(&col, intersect, objects, lights);
		colour_sum(result, col, *result);
		++i;
	}
	result->red /= MONTE_CARLO_MAX_RAYS;
	result->green /= MONTE_CARLO_MAX_RAYS;
	result->blue /= MONTE_CARLO_MAX_RAYS;
	tog = 0;
}
