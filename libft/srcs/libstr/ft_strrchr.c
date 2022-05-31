/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:17:25 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 21:07:27 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strrchr(const char *s, int c)
{
	int		size;

	size = ft_strlen(s);
	while (size >= 0)
	{
		if (s[size] == (unsigned char)c)
			return ((char *)s + (unsigned char)size);
		size--;
	}
	return (NULL);
}
