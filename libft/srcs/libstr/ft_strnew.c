/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:57:36 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 11:13:34 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	index;

	index = 0;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (index < size + 1)
		res[index++] = '\0';
	return (res);
}
