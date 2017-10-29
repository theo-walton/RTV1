/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_object_ray_hits.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 20:39:03 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:29:30 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  RETURNS:
**
**  COORDINATE OF INTERSECTION,
**  DIRECTION OF RAY,
**  OBJECT THAT WAS INTERSECTED
**
**  ALL OF WHICH STORED INSIDE INTERSECT STRUCT
**
**  IF MULTIPLE INTERSECTIONS OCCUR, RETURNS THE FIRST.
**  IF NO INTERSECTIONS OCCUR, RETURNS NULL.
*/

#include "rtv1.h"

static t_intersect	*new_intersect(double dist, t_coor *point,
					t_coor *vector, t_object *obj)
{
	t_intersect *ret;

	ret = malloc(sizeof(t_intersect));
	ret->intersect.x = point->x + vector->x * dist;
	ret->intersect.y = point->y + vector->y * dist;
	ret->intersect.z = point->z + vector->z * dist;
	ret->vector.x = vector->x;
	ret->vector.y = vector->y;
	ret->vector.z = vector->z;
	ret->object = obj;
	return (ret);
}

static int			get_min_dist(double *dist, int total_index)
{
	int		i;
	double	min_dist;
	int		min_index;

	i = 0;
	min_dist = INFIN;
	while (i < total_index)
	{
		if (min_dist > dist[i])
		{
			min_dist = dist[i];
			min_index = i;
		}
		++i;
	}
	return (min_index);
}

static double		get_object_dist(t_coor *point, t_coor *vector,
				t_object *objects, int i)
{
	double dist;

	dist = 0;
	if (objects[i].type == SPHERE)
		dist = get_sphere_dist(point, vector, objects + i);
	else if (objects[i].type == PLANE)
		dist = get_plane_dist(point, vector, objects + i);
	else if (objects[i].type == CYLINDER)
		dist = get_cylinder_dist(point, vector, objects + i);
	else if (objects[i].type == CONE)
		dist = get_cone_dist(point, vector, objects + i);
	return (dist);
}

t_intersect			*get_first_object_ray_hits(t_coor *point, t_coor *vector,
								t_object *objects)
{
	double	dist[1000];
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	while (objects[i].type)
	{
		dist[i] = get_object_dist(point, vector, objects, i);
		if (dist[i] == INFIN)
			++counter;
		++i;
	}
	if (i == counter)
		return (NULL);
	i = get_min_dist(dist, i);
	return (new_intersect(dist[i], point, vector, objects + i));
}
