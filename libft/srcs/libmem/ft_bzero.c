/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:21:43 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:11:45 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

void	ft_bzero(void *s, size_t len)
{
	while (len--)
		((t_uchar *)s)[len] = '\0';
}
