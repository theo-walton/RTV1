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

void	find_colour_of_intersect(t_colour *result, t_intersect *intersect, t_object *objects, t_light *lights)
{
	t_colour col1;
	t_colour col2;

	get_diffuse_col(&col1, intersect, objects, lights);
//	get_indirect_col(&col2, intersect, objects, lights);
//	colour_sum(&col1, col1, col2);
	get_reflect_col(&col2, intersect, objects, lights);
	colour_percent(&col2, intersect->object->shine * 0.9 + intersect->object->shine * 0.1 * rand_fct());
	colour_sum(&col1, col1, col2);
	get_shine(&col2, intersect, objects, lights);
	free(intersect);
	colour_sum(result, col1, col2);
}
