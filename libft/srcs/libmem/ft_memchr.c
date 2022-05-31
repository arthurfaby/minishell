/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:48:28 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:03:14 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		if (((t_uchar *)s)[index] == (t_uchar)c)
			return ((void *)((t_uchar *)(s + index)));
		index++;
	}
	return (NULL);
}
