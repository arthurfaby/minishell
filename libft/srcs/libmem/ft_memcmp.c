/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:54:02 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:14:56 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		if (((t_uchar *)s1)[index] != ((t_uchar *)s2)[index])
			return (((t_uchar *)s1)[index] - ((t_uchar *)s2)[index]);
		index++;
	}
	return (0);
}
