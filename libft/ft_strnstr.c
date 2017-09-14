/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:19:43 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:19:43 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static size_t	min(size_t x, size_t y)
{
	if (x < y)
		return (x);
	return (y);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	substrlen;
	size_t	mainstrlen;
	int		num_searches;

	substrlen = ft_strlen(little);
	mainstrlen = ft_strlen(big);
	if (substrlen == 0)
		return ((char*)big);
	num_searches = (int)min(len, mainstrlen) - (int)substrlen + 1;
	while (num_searches > 0)
	{
		if (ft_memcmp(big, little, substrlen) == 0)
			return ((char*)big);
		big++;
		num_searches--;
	}
	return (NULL);
}
