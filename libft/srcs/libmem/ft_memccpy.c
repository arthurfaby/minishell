/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:57:55 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 21:03:07 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len && ((t_uchar *)src)[index] != (t_uchar)c)
	{
		((t_uchar *)dst)[index] = ((t_uchar *)src)[index];
		index++;
	}
	if (index == len)
		return (NULL);
	((t_uchar *)dst)[index] = ((t_uchar *)src)[index];
	return (dst + index + 1);
}
