/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memndel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:45:24 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/24 08:03:28 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

void	ft_memndel(void **array, size_t len)
{
	size_t	index;

	index = 0;
	if (!array)
		return ;
	while (index < len)
		ft_memdel(array[index++]);
	free(array);
	array = NULL;
}
