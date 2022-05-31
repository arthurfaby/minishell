/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:43:56 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 22:49:52 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void	ft_putsstr(char **str)
{
	int	index_l;
	int	index_c;

	index_l = 0;
	while (str[index_l])
	{
		index_c = 0;
		while (str[index_l][index_c])
		{
			ft_putchar(str[index_l][index_c]);
			index_c++;
		}
		ft_putchar('\n');
		index_l++;
	}
}
