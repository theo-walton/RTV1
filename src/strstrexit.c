/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstrexit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:56:51 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:46:00 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void	exit_function(void)
{
	write(1, "Invalid Format\n", 15);
	exit(1);
}

char		*strstrexit(const char *big, const char *little)
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
		hay = strchrexit(hay, *need);
		if (hay == NULL)
			exit_function();
		if (ft_strncmp(hay, need, needlen) == 0)
		{
			return ((char*)hay);
		}
		hay++;
	}
}
