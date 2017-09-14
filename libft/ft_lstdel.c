/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 23:05:21 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 23:05:22 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *iter;
	t_list *placehold;

	iter = *alst;
	while (iter)
	{
		placehold = iter->next;
		del(iter, iter->content_size);
		iter = placehold;
	}
	*alst = NULL;
}
