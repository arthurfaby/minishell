/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:58:04 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:07:55 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		index;

	if (!*little)
		return ((char *)big);
	if (!len)
		return (NULL);
	while (*big && len)
	{
		if (*big == *little)
		{
			index = 0;
			while (big[index] && little[index] && (len - index)
				&& big[index] == little[index])
				index++;
			if (!little[index])
				return ((char *)big);
			if (!(len - index))
				return (NULL);
		}
		big++;
		len--;
	}
	return (NULL);
}
