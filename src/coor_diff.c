/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:20:37 by twalton           #+#    #+#             */
/*   Updated: 2017/09/04 16:20:37 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	coor_diff(t_coor *result, t_coor coor1, t_coor coor2)
{
	result->x = coor1.x - coor2.x;
	result->y = coor1.y - coor2.y;
	result->z = coor1.z - coor2.z;
}
