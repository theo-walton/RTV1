/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 23:57:12 by twalton           #+#    #+#             */
/*   Updated: 2017/09/10 23:57:12 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	sphere_init(t_object *object, int i)
{
	t_sphere *sphere;

	if (i == 1)
	{
		sphere = malloc(sizeof(t_sphere));
		sphere->center.x = 400;
		sphere->center.y = -300;
		sphere->center.z = 600;
		sphere->radius = 200;
		object->type_info = sphere;
	}
	else
	{
		sphere = malloc(sizeof(t_sphere));
		sphere->center.x = -200;
		sphere->center.y = 200;
		sphere->center.z = 500;
		sphere->radius = 200;
		object->type_info = sphere;
	}
}

static void	plane_init(t_object *object, int i)
{
	t_plane *plane;

	plane = malloc(sizeof(t_plane));
	plane->point.x = 0;
	plane->point.y = 0;
	plane->point.z = 1500;
	plane->normal.x = 0;
	plane->normal.y = 0;
	plane->normal.z = 1;
	object->type_info = plane;
}

static void	cylinder_init(t_object *object, int i)
{
	t_cylinder *cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	cylinder->point.x = 0;
	cylinder->point.y = 0;
	cylinder->point.z = 400;
	cylinder->vector.x = 1;
	cylinder->vector.y = 0;
	cylinder->vector.z = 0;
	cylinder->radius = 100;
	object->type_info = cylinder;
}

t_object	*objects_init(void)
{
	t_object *objects;

	objects = malloc(sizeof(t_object) * 5);
	objects[0].type = SPHERE;
	objects[0].red = 255;
	objects[0].blue = 50;
	objects[0].green = 50;
	objects[0].shine = 0;
	sphere_init(&objects[0], 0);
	objects[1].type = SPHERE;
        objects[1].red = 100;
        objects[1].blue = 255;
        objects[1].green = 100;
        objects[1].shine = 0;
	sphere_init(&objects[1], 1);
	objects[2].type = PLANE;
	objects[2].red = 0;
	objects[2].green = 122;
	objects[2].blue = 233;
	objects[2].shine = 0;
	plane_init(&objects[2], 0);
	objects[3].type = CYLINDER;
	objects[3].red = 233;
	objects[3].green = 119;
	objects[3].blue = 45;
	objects[3].shine = 24;
	cylinder_init(&objects[3], 0);
	objects[3].type = 0;
	return (objects);
}
