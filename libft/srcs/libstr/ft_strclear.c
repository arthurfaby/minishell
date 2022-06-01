/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:53:42 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 07:55:04 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

void	ft_strclear(char *str)
{
	if (!str)
		return ;
	ft_bzero(str, ft_strlen(str));
}