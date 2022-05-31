/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:31:38 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 21:14:57 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int	ft_putnstr_fd(char *s, int n, int fd)
{
	int	count;

	count = 0;
	if (s)
		count += write(fd, s, n);
	return (count);
}
