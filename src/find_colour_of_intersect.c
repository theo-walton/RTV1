/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colour_of_intersect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 16:27:01 by twalton           #+#    #+#             */
/*   Updated: 2017/09/10 16:27:01 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	find_colour_of_intersect(t_intersect *intersect, t_object *objects, t_light *lights)
{
	int col1;
	int col2;

	col1 = get_diffuse_col(intersect, objects, lights);
	col1 = colour_percent(col1, 100 - intersect->object->shine);
	col2 = get_reflect_col(intersect, objects, lights);
	col2 = colour_percent(col2, intersect->object->shine);
	free(intersect);
	return (colour_sum(col1, col2));
}
