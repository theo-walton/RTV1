/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 00:48:29 by twalton           #+#    #+#             */
/*   Updated: 2017/07/27 00:48:29 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chrcount(char *str, char c)
{
	int ret;

	ret = 0;
	while (*str)
	{
		if (*str == c)
			++ret;
		++str;
	}
	return (ret);
}
