/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:44:40 by twalton           #+#    #+#             */
/*   Updated: 2017/09/12 10:44:40 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtv1.h"

void	print_intersect(t_coor *intersect)
{
	printf("(%f, %f, %f)\n", intersect->x, intersect->y, intersect->z);
}
