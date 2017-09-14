/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:53:52 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 15:53:53 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*new;
	const unsigned char	*source;

	new = dest;
	source = src;
	i = n;
	while (i > 0 && *source != (unsigned char)c)
	{
		*new = *source;
		new++;
		source++;
		i--;
	}
	if (i != 0)
	{
		*new = *source;
		return ((void*)(new + 1));
	}
	return (NULL);
}
