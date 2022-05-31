/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:32:50 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 11:12:23 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

int	ft_strequ(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[index] && s2[index] && s1[index] == s2[index])
		index++;
	if (index == ft_strlen(s1) && index == ft_strlen(s2))
		return (1);
	return (0);
}
