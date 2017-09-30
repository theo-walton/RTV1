/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflect_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 19:48:29 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 19:48:29 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_reflect_col(t_colour *result, t_intersect *intersect, t_object *objects, t_light *lights)
{
	t_coor reflect;
	t_intersect *new;
	static unsigned int total_reflections;

	if (result == NULL)
	{
		total_reflections = 0;
		return ;
	}
	zero_colour(result);
	++total_reflections;
	if (total_reflections == MAX_REFLECT)
		return ;
	get_reflection(&reflect, &(intersect->vector), intersect);
	new = get_first_object_ray_hits(&(intersect->intersect), &reflect, objects);
	if (new == NULL)
		return ;
	find_colour_of_intersect(result, new, objects, lights);
}
