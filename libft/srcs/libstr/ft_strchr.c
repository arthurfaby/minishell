/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:14:33 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 08:27:47 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			index;

	index = 0;
	while (index == 0 || s[index - 1])
	{
		if (s[index] == (unsigned char)c)
			return ((char *)s + (char)index);
		index++;
	}
	return (NULL);
}
