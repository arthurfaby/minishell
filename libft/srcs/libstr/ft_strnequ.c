/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:57:33 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 21:02:42 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

int	ft_strnequ(const char *s1, const char *s2, size_t len)
{
	size_t	index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[index] == s2[index] && s1[index] && s2[index] && index < len)
		index++;
	if (index == ft_strlen(s1) && index == ft_strlen(s2) || index == len)
		return (1);
	return (0);
}
