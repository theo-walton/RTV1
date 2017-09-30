/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 00:48:51 by twalton           #+#    #+#             */
/*   Updated: 2017/09/22 00:48:51 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	rand_fct(void)
{
	static int tog;
	double ret;

	if (!tog)
	{
		srand(time(NULL));
		rand();
		rand();
		rand();
		rand();
		tog = 1;
	}
	ret = ((double)rand() / RAND_MAX);
	return (ret);
}
