/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:03:33 by twalton           #+#    #+#             */
/*   Updated: 2017/06/12 15:55:15 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*sor;

	dest = (unsigned char*)dst;
	sor = (const unsigned char*)src;
	if (dest == sor)
		return (dest);
	if (dest < sor)
	{
		while (len > 0)
		{
			*dest++ = *sor++;
			len--;
		}
		return (dst);
	}
	dest = dest + len - 1;
	sor = sor + len - 1;
	while (len > 0)
	{
		*dest-- = *sor--;
		len--;
	}
	return (dest + 1);
}
