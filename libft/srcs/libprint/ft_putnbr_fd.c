/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:20:34 by vnaud             #+#    #+#             */
/*   Updated: 2022/05/12 21:28:14 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	int			count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr_fd(nb / 10, fd);
	count += ft_putchar_fd(((nb % 10) + '0'), fd);
	return (count);
}
