/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:33:08 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 22:50:07 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void	ft_putsstr_fd(char **str, int fd)
{
	int	index_l;
	int	index_c;

	index_l = 0;
	while (str[index_l])
	{
		index_c = 0;
		while (str[index_l][index_c])
		{
			ft_putchar_fd(str[index_l][index_c], fd);
			index_c++;
		}
		ft_putchar_fd('\n', fd);
		index_l++;
	}
}
