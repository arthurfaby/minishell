/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:19:07 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/26 21:13:21 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int	ft_putendl(char *s)
{
	return (ft_putendl_fd(s, 1));
}