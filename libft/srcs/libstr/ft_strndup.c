/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:54:36 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/27 20:57:06 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strndup(const char *src, size_t len)
{
	char	*res;

	res = ft_strnew(len + 1);
	if (!res)
		return (NULL);
	res = ft_strncpy(res, src, len);
	res[len] = '\0';
	return (res);
}
