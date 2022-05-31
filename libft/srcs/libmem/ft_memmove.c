/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:33:34 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:15:31 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if ((dst == NULL && src == NULL) || len == 0)
		return (dst);
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	while (len--)
		((char *)dst)[len] = ((char *)src)[len];
	return (dst);
}
