/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:49:10 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 15:49:12 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	logic(int n, int digits, int sign, char *str)
{
	if (str == NULL)
		return ;
	if (sign)
	{
		str[0] = '-';
		n = -n;
	}
	str[digits + sign] = '\0';
	while (n)
	{
		str[digits + sign - 1] = n % 10 + '0';
		n = n / 10;
		digits--;
	}
}

static char	*mint(void)
{
	char *str;

	str = malloc(sizeof(char) * 12);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		digits[3];
	char	*str;

	digits[1] = 0;
	digits[2] = n;
	digits[0] = 0;
	if (n == -2147483648)
		return (mint());
	if (n == 0)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (digits[2])
	{
		digits[2] = digits[2] / 10;
		digits[0]++;
	}
	if (n < 0)
		digits[1] = 1;
	str = malloc(sizeof(char) * (digits[0] + digits[1] + 1));
	logic(n, digits[0], digits[1], str);
	return (str);
}
