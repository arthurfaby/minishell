/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:24:20 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:07:06 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		size_dst;
	size_t		tmp;

	tmp = size;
	d = dst;
	s = src;
	while (tmp-- != 0 && *d)
		d++;
	size_dst = d - dst;
	tmp = size - size_dst;
	if (tmp == 0)
		return (size_dst + ft_strlen(s));
	while (*s)
	{
		if (tmp != 1)
		{
			*d++ = *s;
			tmp--;
		}
		s++;
	}
	*d = '\0';
	return (size_dst + (s - src));
}
