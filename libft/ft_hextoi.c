/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 01:00:29 by twalton           #+#    #+#             */
/*   Updated: 2017/08/10 01:00:29 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	val(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (0);
}

static int	is_hexdig(char c)
{
	if (ft_isdigit(c))
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	if (c >= 'a' && c <= 'f')
		return (1);
	return (0);
}

int			ft_hextoi(char *str)
{
	int i;
	int tot;

	tot = 0;
	i = -1;
	while (is_hexdig(str[++i]))
		tot = val(str[i]) + tot * 16;
	return (tot);
}
