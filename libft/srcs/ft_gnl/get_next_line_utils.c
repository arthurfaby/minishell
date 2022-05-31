/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:29:52 by vnaud             #+#    #+#             */
/*   Updated: 2022/05/03 09:05:16 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

char	*ft_strjoins(char *s1, char *s2)
{
	char	*res;
	int		index;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	res[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	if (res == NULL)
		return (res);
	index = -1;
	while (s1[++index])
		res[index] = s1[index];
	while (*s2)
		res[index++] = *s2++;
	free(s1);
	s1 = NULL;
	return (res);
}
