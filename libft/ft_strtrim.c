/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:23:58 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:24:00 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	wspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static char	*norm25linelimit(void)
{
	char *str;

	str = malloc(sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = '\0';
	return (str);
}

static int	isempty(char const *s)
{
	while (wspace(*s))
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*newstr;

	i = 0;
	if (isempty(s))
		return (norm25linelimit());
	while (wspace(s[i]))
		i++;
	start = i;
	while (s[i])
		i++;
	i--;
	while (wspace(s[i]))
		i--;
	end = i;
	newstr = malloc(sizeof(char) * (end - start + 2));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (start != end + 1)
		newstr[i++] = s[start++];
	newstr[i] = '\0';
	return (newstr);
}
