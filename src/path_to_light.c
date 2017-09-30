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

static int	distance_check(t_intersect *intersect, t_coor coor, double dist)
{
	double obj_dist;
	t_coor difference;

	coor_diff(&difference, intersect->intersect, coor);
	obj_dist = sqrt(dot_product(difference, difference));
	if (obj_dist > dist)
	{
		free(intersect);
		return (1);
	}
	free(intersect);
	return (0);
}

int	path_to_light(t_coor coor, t_object *objects, t_light *light)
{
	t_coor vector;
	double dist;
	t_intersect *intersect;

	vector.x = light->x - coor.x;
	vector.y = light->y - coor.y;
	vector.z = light->z - coor.z;
	dist = vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
	dist = sqrt(dist);
	vector.x /= dist;
	vector.y /= dist;
	vector.z /= dist;
	if ((intersect = get_first_object_ray_hits(&coor, &vector, objects)))
		return (distance_check(intersect, coor, dist));
	return (1);
}
