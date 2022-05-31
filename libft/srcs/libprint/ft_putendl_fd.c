/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:19:07 by vnaud             #+#    #+#             */
/*   Updated: 2022/05/13 06:58:28 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		return (count);
	while (*s)
		count += write(fd, s++, 1);
	count += write(fd, "\n", 1);
	return (count);
}
