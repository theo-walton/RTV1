/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:21:09 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 16:21:09 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	countwords(char const *s, char c)
{
	int i;
	int toggle;
	int n;

	i = 0;
	toggle = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			toggle = 1;
		}
		if (toggle)
			n++;
		toggle = 0;
	}
	return (n);
}

static int	makestr(char const *start, char const *end, char *dest)
{
	int i;

	i = 0;
	if (dest == NULL)
		return (0);
	while (start + i != end)
	{
		dest[i] = start[i];
		i++;
	}
	dest[i] = '\0';
	return (1);
}

static char	**mallocfail(char ***strarr, int wordfail)
{
	while (wordfail != -1)
	{
		free(**strarr + wordfail);
		wordfail--;
	}
	free(*strarr);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		w[2];
	int		placehold;
	char	**strarr;

	if (!s || (w[1] = countwords(s, c)) < 0)
		return (NULL);
	strarr = malloc(sizeof(char*) * (w[1] + 1));
	i = 0;
	w[0] = 0;
	while (w[0] != w[1] && strarr != NULL)
	{
		while (s[i] == c)
			i++;
		placehold = i;
		while (s[placehold] != c && s[placehold] != '\0')
			placehold++;
		strarr[w[0]] = malloc(sizeof(char) * (placehold - i + 1));
		if (makestr(s + i, s + placehold, strarr[w[0]++]) == 0)
			strarr = mallocfail(&strarr, w[0] - 2);
		i = placehold;
	}
	if (strarr != NULL)
		strarr[w[1]] = NULL;
	return (strarr);
}
