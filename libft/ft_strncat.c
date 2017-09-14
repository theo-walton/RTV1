/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:15:56 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:15:58 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*destend;
	const char	*source;
	size_t		i;

	i = n;
	source = s2;
	destend = s1 + ft_strlen(s1);
	while (*source && i)
	{
		*destend = *source;
		destend++;
		source++;
		i--;
	}
	*destend = '\0';
	return (s1);
}
