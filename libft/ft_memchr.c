/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:00:26 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:00:27 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	size_t				i;

	src = s;
	i = n;
	while (i > 0 && *src != (unsigned char)c)
	{
		src++;
		i--;
	}
	if (i != 0)
	{
		return ((void*)src);
	}
	return (NULL);
}
