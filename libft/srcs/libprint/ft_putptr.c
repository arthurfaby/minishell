/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:48:35 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 22:48:22 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

static int	ft_putullnbr_base(unsigned long long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr > (unsigned long long)(ft_strlen(base) - 1))
		count += ft_putullnbr_base(nbr / ft_strlen(base), base);
	count += ft_putchar(base[nbr % ft_strlen(base)]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putullnbr_base((unsigned long long)ptr, "0123456789abcdef");
	return (count);
}
