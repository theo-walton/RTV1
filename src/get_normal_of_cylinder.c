/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_of_cylinder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 23:54:10 by twalton           #+#    #+#             */
/*   Updated: 2017/09/18 23:54:10 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_normal_of_cylinder(t_coor *normal, t_intersect *intersect)
{
	normal->x = 0;
	normal->y = 0;
	normal->z = 1;
}
