/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:14:06 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 20:50:19 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

static int	ft_value_base(const char c)
{
	int	res;

	res = -42;
	if (c >= '0' && c <= '9')
		res = c - '0';
	else if (c >= 'a' && c <= 'z')
		res = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		res = c - 'A' + 10;
	return (res);
}

int	ft_atoi_base(char *str, int base)
{
	size_t	res;
	int		neg;
	int		tmp;

	res = 0;
	neg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			neg = -1;
	while (ft_value_base(*str) != -42)
	{
		tmp = ft_value_base(*str);
		res *= base;
		res += tmp;
		str++;
	}
	if (res > (size_t)2147483648 && neg < 0)
		return (0);
	if (res > (size_t)2147483647 && neg > 0)
		return (-1);
	return ((int)res * neg);
}
