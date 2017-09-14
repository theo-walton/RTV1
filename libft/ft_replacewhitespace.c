/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacewhitespace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:32:09 by twalton           #+#    #+#             */
/*   Updated: 2017/08/17 13:32:09 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replacewhitespace(char *str, char c)
{
	char	*p;
	char	*q;

	q = str;
	while (1)
	{
		while (!ft_isspace(*q))
		{
			if (!*q)
				return ;
			++q;
		}
		p = q;
		while (ft_isspace(*q))
			++q;
		*p = c;
		ft_memmove(++p, q, ft_strlen(q) + 1);
		q = p;
	}
}
