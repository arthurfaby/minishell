/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:27:45 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 20:33:23 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t	index;
	size_t	size;

	index = 0;
	size = 0;
	while (dst[index])
		index++;
	while (size < len && src[size])
		dst[index++] = src[size++];
	dst[index] = '\0';
	return (dst);
}
