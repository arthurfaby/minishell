/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:06:07 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 08:22:55 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	index_dest;
	int	index_src;

	index_dest = 0;
	index_src = 0;
	while (dest[index_dest])
	{
		index_dest++;
	}
	while (src[index_src])
	{
		dest[index_dest + index_src] = src[index_src];
		index_src++;
	}
	dest[index_dest + index_src] = '\0';
	return (dest);
}
