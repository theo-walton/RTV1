/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freepart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 17:40:09 by twalton           #+#    #+#             */
/*   Updated: 2017/06/18 17:40:09 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_shortenstr(char *str, char *new_str_end)
{
	char *temp;
	char c;

	c = *new_str_end;
	*new_str_end = '\0';
	temp = ft_strdup(str);
	if (temp == NULL)
	{
		*new_str_end = c;
		return (NULL);
	}
	free(str);
	return (temp);
}
