/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:20:51 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:07:15 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	size_src;

	size_src = 0;
	while (src[size_src])
		size_src++;
	if (size == 0)
		return (size_src);
	while (*src && --size > 0)
		*dst++ = *src++;
	*dst = '\0';
	return (size_src);
}
