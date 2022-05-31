/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:30:09 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:02:58 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	size_res;
	size_t	index;

	index = 0;
	if (nmemb <= 0 || size <= 0)
		return (malloc(1));
	size_res = nmemb * size;
	if (size_res > 2147483647)
		return (malloc(1));
	res = malloc(nmemb * size);
	if (res == NULL)
		return (res);
	while (index < size_res)
		res[index++] = 0;
	return (res);
}
