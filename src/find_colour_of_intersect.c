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

	col2 = 0;
	col1 = get_diffuse_col(intersect, objects, lights);
	col2 = get_reflect_col(intersect, objects, lights);
	col2 = colour_percent(col2, intersect->object->shine);
	free(intersect);
	col1 = colour_sum(col1, col2);
	col2 = get_shine(intersect, objects, lights);
	return (colour_sum(col1, col2));
}
