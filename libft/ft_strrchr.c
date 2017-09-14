/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:20:33 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:20:34 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *str;

	str = s;
	str = str + ft_strlen(str);
	while (*str != c)
	{
		if (str == s)
			return (NULL);
		str--;
	}
	return ((char*)str);
}
