/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:17:37 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:17:37 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	const char	*source;
	char		*destination;
	size_t		i;

	source = src;
	destination = dst;
	i = len;
	while (i > 0 && *source != '\0')
	{
		*destination = *source;
		source++;
		destination++;
		i--;
	}
	while (i > 0)
	{
		*destination = '\0';
		destination++;
		i--;
	}
	return (dst);
}
