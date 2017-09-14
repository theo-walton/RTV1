/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 18:03:23 by twalton           #+#    #+#             */
/*   Updated: 2017/06/09 18:03:24 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	freelists(t_list *start, t_list *list_failure)
{
	t_list *temp;

	while (start != list_failure)
	{
		temp = start;
		start = start->next;
		free(temp);
	}
	free(start);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list_start;
	t_list *list;

	if (!lst)
		return (NULL);
	list = f(lst);
	list_start = list;
	while (lst->next)
	{
		lst = lst->next;
		if ((list->next = f(lst)) == NULL)
		{
			freelists(list_start, list);
			return (NULL);
		}
		list = list->next;
	}
	return (list_start);
}
