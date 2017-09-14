/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:13:31 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:13:32 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t ss;
	size_t ds;

	i = 0;
	ds = 0;
	ss = ft_strlen(src);
	while (dst[ds] && ds < size)
		ds++;
	if (ds == size)
		return (size + ss);
	while (src[i] && ds + i + 1 < size)
	{
		dst[i + ds] = src[i];
		i++;
	}
	dst[i + ds] = '\0';
	return (ss + ds);
}
