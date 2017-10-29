/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchrexit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:59:49 by twalton           #+#    #+#             */
/*   Updated: 2017/10/29 09:45:24 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void	exit_function(void)
{
	write(1, "Invalid Format\n", 15);
	exit(1);
}

char		*strchrexit(const char *s, int c)
{
	const char *str;

	str = s;
	while (*str != c && *str != '\0')
		str++;
	if (*str == '\0' && c != 0)
		exit_function();
	return ((char*)str);
}
