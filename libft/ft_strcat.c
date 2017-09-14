/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:07:39 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:07:40 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char		*destend;
	const char	*source;

	source = s2;
	destend = s1 + ft_strlen(s1);
	while (*source)
	{
		*destend = *source;
		destend++;
		source++;
	}
	*destend = '\0';
	return (s1);
}
