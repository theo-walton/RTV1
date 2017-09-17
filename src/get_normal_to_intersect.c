/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_to_intersect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:51:43 by twalton           #+#    #+#             */
/*   Updated: 2017/09/14 20:51:43 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** NOTE: does not guarantee normal is of unit length
*/

void	get_normal_to_intersect(t_coor *normal, t_intersect *intersect)
{
	if (intersect->object->type == SPHERE)
	{
		get_normal_of_sphere(normal, intersect);
		return ;
	}
}
