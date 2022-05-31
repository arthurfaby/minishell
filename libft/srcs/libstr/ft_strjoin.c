/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:05:59 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 11:12:57 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		index;
	int		index2;

	if (!s1 || !s2)
		return (NULL);
	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	index = -1;
	while (s1[++index])
		res[index] = s1[index];
	index2 = -1;
	while (s2[++index2])
		res[index + index2] = s2[index2];
	res[index + index2] = '\0';
	return (res);
}
