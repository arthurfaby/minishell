/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:44:59 by vnaud             #+#    #+#             */
/*   Updated: 2022/05/13 07:32:48 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	index;

	res = NULL;
	index = 0;
	if (!s)
		return (NULL);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (index < len)
	{
		res[index] = s[index + start];
		index++;
	}
	res[index] = '\0';
	return (res);
}
