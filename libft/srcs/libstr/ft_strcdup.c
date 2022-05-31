/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:45:57 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 07:51:53 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strcdup(const char *str, char c)
{
	char	*res;
	int		index;

	index = 0;
	while (str[index] && str[index] != c)
		index++;
	res = malloc(sizeof(char) * (index + 1));
	if (!res)
		return (NULL);
	res[index] = '\0';
	while (--index >= 0)
		res[index] = str[index];
	return (res);
}
