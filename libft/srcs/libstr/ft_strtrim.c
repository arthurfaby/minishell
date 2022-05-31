/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:27:27 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 21:25:57 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

static int	ft_inset(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *c)
{
	size_t	size;
	char	*res;

	if (!s || !c)
		return (NULL);
	while (*s && ft_inset(*s, c))
		s++;
	size = ft_strlen(s);
	if (size != 0)
		while (ft_strchr(c, s[size - 1]))
			size--;
	res = ft_strnew(size + 1);
	if (!res)
		return (NULL);
	ft_strncpy(res, s, size + 1);
	res[size] = '\0';
	return (res);
}
