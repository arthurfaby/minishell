/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:15:18 by vnaud             #+#    #+#             */
/*   Updated: 2022/05/12 21:25:35 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

int	ft_atoi(const char *nptr)
{
	long	res;
	int		neg;

	res = 0;
	neg = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			neg = -1;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += (*nptr - '0');
		nptr++;
	}
	if (res > 2147483648 && neg < 0)
		return (0);
	if (res > 2147483647 && neg > 0)
		return (-1);
	return ((int)res * neg);
}
