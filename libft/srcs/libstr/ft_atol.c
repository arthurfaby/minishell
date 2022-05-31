/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:35:21 by vnaud             #+#    #+#             */
/*   Updated: 2022/05/11 18:02:46 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

long	ft_atol(const char *nptr)
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
	while (*nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += *nptr - '0';
		nptr++;
	}
	return (res * neg);
}
