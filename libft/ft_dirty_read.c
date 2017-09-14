/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirty_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 23:44:27 by twalton           #+#    #+#             */
/*   Updated: 2017/07/23 23:44:27 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_dirty_read(int fd, int size)
{
	char	*buf;
	int		bytes_read;

	if (!(buf = malloc(sizeof(char) * size)))
		return (0);
	bytes_read = read(fd, buf, size);
	if (bytes_read == size || bytes_read < 0)
	{
		free(buf);
		return (0);
	}
	buf[bytes_read] = '\0';
	return (buf);
}
