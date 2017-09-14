/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:02:24 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:02:25 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*new;
	const unsigned char	*source;

	new = dest;
	source = src;
	i = n;
	while (i > 0)
	{
		*new = *source;
		new++;
		source++;
		i--;
	}
	return (dest);
}
