/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:49:15 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 21:30:28 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

static char	ft_value_base(int n)
{
	char	res;

	res = -42;
	if (n >= 0 && n <= 9)
		res = n + '0';
	else if (n <= 35)
		res = n + 'a' - 10;
	return (res);
}

static int	ft_size_num_base(long long int n, int base)
{
	size_t	size_num;

	size_num = 0;
	if (n <= 0)
		size_num++;
	while (n)
	{
		size_num++;
		n = n / base;
	}
	return (size_num);
}

char	*ft_itoa_base(long long int n, int base)
{
	char			*res;
	long long int	tmp;
	size_t			size;

	tmp = n;
	size = ft_size_num_base(tmp, base);
	res = malloc(sizeof(char) * (size + 1));
	if (!res || base < 2 || base > 36)
		return (NULL);
	if (n < 0)
	{
		tmp *= -1;
		res[0] = '-';
	}
	res[size] = '\0';
	if (tmp == 0)
		res[--size] = '0';
	while (tmp != 0)
	{
		size--;
		res[size] = ft_value_base(tmp % base);
		tmp /= base;
	}
	return (res);
}
