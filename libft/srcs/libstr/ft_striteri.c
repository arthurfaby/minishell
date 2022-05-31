/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:08:15 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 08:40:06 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	index;

	index = -1;
	if (!s || !f)
		return ;
	while (s[++index])
		f(index, &s[index]);
}
