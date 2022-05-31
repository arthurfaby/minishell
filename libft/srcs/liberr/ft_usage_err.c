/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:01:49 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 17:52:04 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liberr.h"

void	ft_usage_err(char *name, char *params)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(params, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
