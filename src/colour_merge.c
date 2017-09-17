/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 16:38:10 by twalton           #+#    #+#             */
/*   Updated: 2017/09/14 16:38:10 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	colour_merge(int col1, int col2)
{
	int redav;
	int blueav;
	int greenav;

	blueav = col1 % 256 + col2 % 256;
	col1 /= 256;
	col2 /= 256;
	greenav = col1 % 256 + col2 % 256;
	col1 /= 256;
	col2 /= 256;
	redav = col1 % 256 + col2 % 256;
	blueav /= 2;
	greenav /= 2;
	redav /= 2;
	return (blueav + 256 * greenav + 256 * 256 * redav);
}
