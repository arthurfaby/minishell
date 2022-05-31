/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:40:58 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 07:45:26 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strtolower(char *str)
{
	int	index;

	index = -1;
	if (!str)
		return (str);
	while (str[++index])
		str[index] = ft_tolower(str[index]);
	return (str);
}
