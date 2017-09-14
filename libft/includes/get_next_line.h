/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 01:07:04 by twalton           #+#    #+#             */
/*   Updated: 2017/06/19 01:07:04 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10000
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int	get_next_line(int fd, char **line);

#endif
