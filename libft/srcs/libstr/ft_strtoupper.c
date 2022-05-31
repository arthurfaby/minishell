/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:44:15 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 07:45:38 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strtoupper(char *str)
{
	int	index;

	index = -1;
	if (!str)
		return (str);
	while (str[++index])
		str[index] = ft_toupper(str[index]);
	return (str);
}
