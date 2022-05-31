/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:26:40 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 22:46:16 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char c, va_list params)
{
	if (c == 'c')
		return (ft_putchar(va_arg(params, int)));
	if (c == 's')
		return (ft_putstr(va_arg(params, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(params, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(params, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(params, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(params, unsigned int), c));
	if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		size;

	va_start(params, str);
	size = 0;
	while (*str)
	{
		if (*str == '%')
		{
			size += ft_type(*(str + 1), params);
			str++;
		}
		else
		{
			ft_putchar(*str);
			size++;
		}
		str++;
	}
	va_end(params);
	return (size);
}
