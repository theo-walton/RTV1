/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_of_cone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 21:36:10 by twalton           #+#    #+#             */
/*   Updated: 2017/10/10 21:36:10 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_normal_of_cone(t_coor *normal, t_intersect *intersect)
{
	normal->x = 1;
	normal->y = 1;
	normal->z = 0;
}
