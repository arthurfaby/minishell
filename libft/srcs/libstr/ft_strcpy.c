/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:02:34 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 11:10:54 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	index;

	index = -1;
	while (src[++index])
		dst[index] = src[index];
	dst[index] = '\0';
	return (dst);
}
