/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:08:24 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:08:26 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	const char *str;

	if (!s)
		return (NULL);
	str = s;
	while (*str != c && *str != '\0')
		str++;
	if (*str == '\0' && c != 0)
		return (NULL);
	return ((char*)str);
}
