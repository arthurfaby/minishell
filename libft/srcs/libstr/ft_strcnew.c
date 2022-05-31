/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:01:03 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 11:10:05 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strcnew(size_t size, char c)
{
	char	*res;
	size_t	index;

	index = 0;
	res = ft_strnew(size);
	if (!res)
		return (NULL);
	while (index < size + 1)
		res[index++] = c;
	return (res);
}
