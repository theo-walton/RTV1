/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:50:16 by twalton           #+#    #+#             */
/*   Updated: 2017/06/20 20:59:12 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*free_and_return(char *p)
{
	free(p);
	return (NULL);
}

char	*because_norm(char **remainder, int i)
{
	if (i == 2)
	{
		free(*remainder);
		*remainder = NULL;
		return (NULL);
	}
	if (*remainder)
		return (ft_strdup(*remainder));
	return (ft_strnew(0));
}

char	*read_until_next_line(int fd, char *remainder)
{
	char	buf[BUFF_SIZE + 1];
	int		bytes_read;
	char	*total;
	char	*p;

	bytes_read = BUFF_SIZE;
	buf[0] = '\0';
	total = because_norm(&remainder, 1);
	if (!total)
		return (NULL);
	while (!ft_strchr(buf, '\n') && bytes_read == BUFF_SIZE)
	{
		p = total;
		if ((bytes_read = read(fd, buf, BUFF_SIZE)) < 0)
			return (free_and_return(p));
		buf[bytes_read] = '\0';
		if ((total = ft_securejoin(total, buf)) == NULL)
			return (free_and_return(p));
		free(p);
	}
	return (total);
}

int		get_next_line(int fd, char **line)
{
	static char	*remainder[572];
	char		*str;
	char		*p;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (ft_strchr(remainder[fd % 572], '\n'))
		str = remainder[fd % 572];
	else if ((str = read_until_next_line(fd, remainder[fd % 572])) == NULL)
	{
		because_norm(&remainder[fd % 572], 2);
		return (-1);
	}
	if (!ft_strlen(str))
		return (0);
	if ((p = ft_strchr(str, '\n')) == NULL)
	{
		*line = str;
		free(remainder[fd % 572]);
		remainder[fd % 572] = NULL;
		return (1);
	}
	remainder[fd % 572] = ft_strdup(p + 1);
	*line = ft_shortenstr(str, p);
	return (1);
}
