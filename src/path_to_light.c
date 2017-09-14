/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_to_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 16:34:54 by twalton           #+#    #+#             */
/*   Updated: 2017/09/10 16:34:54 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	path_to_light(t_coor coor, t_object *objects, t_light *light)
{
	t_coor vector;
	double divisor;
	void *free_me;

	vector.x = light->x - coor.x;
	vector.y = light->y - coor.y;
	vector.z = light->z - coor.z;
	divisor = vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
	divisor = sqrt(divisor);
	vector.x /= divisor;
	vector.y /= divisor;
	vector.z /= divisor;
	if ((free_me = get_first_object_ray_hits(&coor, &vector, objects)))
	{
		free(free_me);
		return (0);
	}
	return (1);
}
