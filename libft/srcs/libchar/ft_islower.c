/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:59:48 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 21:55:41 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libchar.h"

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}