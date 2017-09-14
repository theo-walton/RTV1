/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:29:01 by twalton           #+#    #+#             */
/*   Updated: 2017/06/07 15:29:14 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(const char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	edgecase(long long int value, int sign)
{
	if (value * sign > 2147483647)
		return (-1);
	if (value * sign < -2147483648)
		return (0);
	if (value * sign == -2147483648)
		return (-2147483648);
	return (1);
}

int			ft_atoi(const char *str)
{
	int				sign;
	long long int	value;
	const char		*ptr;

	ptr = str;
	sign = 1;
	value = 0;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	else if (*ptr == '+')
		ptr++;
	while (*ptr <= '9' && *ptr >= '0')
	{
		value = (*ptr - '0') + value * 10;
		if (edgecase(value, sign) != 1)
			return (edgecase(value, sign));
		ptr++;
	}
	return (sign * value);
}
