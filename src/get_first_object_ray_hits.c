/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_object_ray_hits.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 15:57:30 by twalton           #+#    #+#             */
/*   Updated: 2017/09/10 15:57:30 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	get_intersect_dist(t_coor *point, t_coor *vector, t_intersect *intersect)
{
	double d;

	if (intersect->object == NULL)
		return (INFIN);
	if (vector->x)
	{
		d = intersect->intersect.x - point->x;
		return (d / vector->x);
	}
	if (vector->y)
	{
		d = intersect->intersect.y - point->y;
		return (d / vector->y);
	}
	d = intersect->intersect.z - point->z;
	return (d / vector->z);
}

static void	get_min_intersection(t_coor *point, t_coor *vector, t_intersect *intersects, int i)
{
	int min_index;
	double min_dist;
	double dist;

	min_dist = INFIN;
	while (i)
	{
		print_intersect(&intersects[i - 1].intersect);
		dist = get_intersect_dist(point, vector, intersects + i - 1);
		if (dist < min_dist)
		{
			min_dist = dist;
			min_index = i - 1;
		}
		--i;
	}
	ft_memmove(intersects, intersects + min_index, sizeof(t_intersect));
}

static t_intersect	*copy_intersect(t_intersect *src)
{
	t_intersect *dest;

	if (!(dest = malloc(sizeof(t_intersect))))
		exit(1);
	ft_memmove(dest, src, sizeof(t_intersect));
	return (dest);
}

t_intersect	*get_first_object_ray_hits(t_coor *point, t_coor *vector, t_object *objects)
{
	t_intersect intersects[1000];
	t_intersect *ret;
	int counter;
	int i;

	counter = 0;
	i = 0;
	while (objects[i].type)
	{
		if (objects[i].type == SPHERE)
			if (!get_sphere_intersections(intersects + 2 * i, objects + i, point, vector))
				++counter;
		++i;
	}
	if (i == counter)
		return (NULL);
	get_min_intersection(point, vector, intersects, 2 * i);
	print_intersect(&intersects[0].intersect);
	write(1, "____", 4);
	ret = copy_intersect(intersects);
	return (ret);
}
