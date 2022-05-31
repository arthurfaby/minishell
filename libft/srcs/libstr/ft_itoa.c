/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:20:52 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 20:47:42 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

static int	ft_size_num(long int n)
{
	size_t	size_num;

	size_num = 0;
	if (n <= 0)
		size_num++;
	while (n)
	{
		size_num++;
		n = n / 10;
	}
	return (size_num);
}

char	*ft_itoa(int n)
{
	char		*res;
	long int	tmp;
	size_t		size;

	tmp = n;
	size = ft_size_num(tmp);
	res = malloc(sizeof(char) * (size + 1));
	if (res == NULL)
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
		res[size] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (res);
}
