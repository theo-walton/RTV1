/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstroccur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:55:30 by twalton           #+#    #+#             */
/*   Updated: 2017/07/27 17:55:30 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** similar to ft_strstr this function will give the nth occurence of a string
** 'sub' inside the string 'main', or NULL if there is no nth occurence.
** n >= 1 as valid input.
*/

char	*ft_strstroccur(char *main, char *sub, size_t n)
{
	char *p;

	p = main - 1;
	while (n-- > 0)
	{
		++p;
		p = ft_strstr(p, sub);
	}
	return (p);
}
