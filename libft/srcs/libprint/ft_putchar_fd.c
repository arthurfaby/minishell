/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:13:36 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 21:13:13 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}