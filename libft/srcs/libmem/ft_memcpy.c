/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:22:14 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:03:29 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dest == NULL && src == NULL)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
