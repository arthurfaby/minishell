/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:45:11 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 22:47:07 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > UINT_MAX)
		return (0);
	if (n >= 10)
		count += ft_putunbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
