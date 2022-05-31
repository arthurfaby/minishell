/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:57:24 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 22:12:34 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int	ft_puthex(unsigned int n, char hex)
{
	int		count;
	char	*base;

	count = 0;
	if (hex == 'x')
		base = "0123456789abcdef";
	else if (hex == 'X')
		base = "0123456789ABCDEF";
	else
		return (count);
	if (n > (unsigned int)(ft_strlen(base) - 1))
		count += ft_puthex(n / ft_strlen(base), hex);
	count += ft_putchar(base[n % ft_strlen(base)]);
	return (count);
}
