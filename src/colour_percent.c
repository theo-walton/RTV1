/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 19:21:45 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 19:21:45 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	colour_percent(t_colour *result, double percent)
{
	result->red *= percent / 100;
	result->green *= percent / 100;
	result->blue *= percent / 100;
}
