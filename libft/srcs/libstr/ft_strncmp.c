/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:22:02 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 20:35:10 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;

	index = 0;
	while (s1[index] && s2[index] && index < n && s1[index] == s2[index])
		index++;
	if (index == n)
		return (0);
	return (((unsigned char)s1[index] - (unsigned char)s2[index]));
}
