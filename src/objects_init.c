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
		sphere->center.x = 0;
		sphere->center.y = 0;
		sphere->center.z = 1000;
		sphere->radius = 200;
		object->type_info = sphere;
	}
	else
	{
		sphere = malloc(sizeof(t_sphere));
		sphere->center.x = 20;
		sphere->center.y = 20;
		sphere->center.z = 400;
		sphere->radius = 40;
		object->type_info = sphere;
	}
}

t_object	*objects_init(void)
{
	t_object *objects;

	objects = malloc(sizeof(t_object) * 2);
	objects[0].type = SPHERE;
	objects[0].red = 255;
	objects[0].blue = 100;
	objects[0].green = 100;
	objects[0].shine = 0;
	sphere_init(&objects[0], 0);
	objects[1].type = SPHERE;
        objects[1].red = 255;
        objects[1].blue = 100;
        objects[1].green = 100;
        objects[1].shine = 0;
	sphere_init(&objects[1], 1);
	objects[2].type = 0;
	return (objects);
}
