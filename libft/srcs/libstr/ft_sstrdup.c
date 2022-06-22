/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:44:07 by vnaud             #+#    #+#             */
/*   Updated: 2022/06/22 18:32:45 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	**ft_sstrdup(char **sstr)
{
	int		index;
	char	**res;

	index = 0;
	if (!sstr || !*sstr)
		return (NULL);
	while (sstr[index])
		index++;
	res = malloc(sizeof(char *) * (index + 1));
	if (!res)
		return (NULL);
	index = -1;
	while (sstr[++index])
		res[index] = ft_strdup(sstr[index]);
	res[index] = NULL;
	return (res);
}
