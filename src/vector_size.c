/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:48:36 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:46:40 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	vector_size(t_coor vector)
{
	return (sqrt(
		vector.x * vector.x +
		vector.y * vector.y +
		vector.z * vector.z));
}
