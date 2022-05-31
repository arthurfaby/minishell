/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:58:34 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 22:33:28 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liberr.h"

void	ft_exit_msg(char *message, int fd)
{
	if (fd == 2)
	{
		if (message)
			ft_putstr_fd(message, 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (message)
			ft_putstr_fd(message, 1);
		exit(EXIT_SUCCESS);
	}
}
