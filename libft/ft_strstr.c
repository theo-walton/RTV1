/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:22:20 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:22:21 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*hay;
	const char	*need;
	size_t		needlen;

	needlen = ft_strlen(little);
	if (needlen == 0)
		return ((char*)big);
	hay = big;
	need = little;
	while (1)
	{
		hay = ft_strchr(hay, *need);
		if (hay == NULL)
			return (NULL);
		if (ft_strncmp(hay, need, needlen) == 0)
		{
			return ((char*)hay);
		}
		hay++;
	}
}
