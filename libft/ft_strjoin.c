/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:12:58 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:12:59 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*newstr;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = malloc(sizeof(newstr) * (len1 + len2 + 1));
	if (newstr == NULL)
		return (NULL);
	while (i < len1)
	{
		newstr[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		newstr[i] = s2[i - len1];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
