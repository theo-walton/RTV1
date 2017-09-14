/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 01:47:54 by twalton           #+#    #+#             */
/*   Updated: 2017/07/05 01:47:54 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	str_extend(char **str, int bytes)
{
	char *temp;

	temp = ft_strnew(ft_strlen(*str) + bytes);
	if (temp)
		temp = ft_strcpy(temp, *str);
	free(*str);
	*str = temp;
	if (temp)
		return (1);
	return (0);
}

char		*ft_createstr(char c, int chunk_size)
{
	static char	*str;
	static int	i;

	if (c == '\0')
		return (str);
	if (chunk_size <= 0)
	{
		str = NULL;
		i = 0;
		return (NULL);
	}
	if (!str)
		if (!(str = ft_strnew(chunk_size)))
			return (NULL);
	str[i] = c;
	i++;
	if (i % chunk_size == 0)
	{
		if (!str_extend(&str, chunk_size))
			return (NULL);
	}
	return (str);
}

/*
** call this function to create a string of size "chunk_size" and
** add the chatacter "c" to the end of the string. If the string
** would exceed its size, additional space of "chunk_size" is created.
** Each future function call will add an additional character to the
** string.
**
** return values:
**
** this will return the new string that has been created or NULL if
** malloc failed / function was reset.
**
** notes:
**
** . the string can be edited between funtion calls
** . entering chunk size <= 0 will reset the function.
** . entering '\0' will do nothing to the string but return the
**   current string held by the function.
*/
