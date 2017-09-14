/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:03:22 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 17:03:23 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if ((new = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((new->content = malloc(content_size)) == NULL)
	{
		free(new);
		return (NULL);
	}
	if (content == NULL)
	{
		new->content_size = 0;
		free(new->content);
		new->content = NULL;
	}
	else
	{
		new->content_size = content_size;
		ft_memcpy(new->content, content, content_size);
	}
	new->next = NULL;
	return (new);
}
