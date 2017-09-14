/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:10:50 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:10:51 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	const char	*str;
	char		*dup;
	size_t		i;

	str = s1;
	i = ft_strlen(str);
	dup = (char*)malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	while (*str)
	{
		*dup = *str;
		dup++;
		str++;
	}
	*dup = '\0';
	return (dup - i);
}
