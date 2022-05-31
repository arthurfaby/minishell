/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:57:18 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:05:12 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*it;

	if (lst == NULL)
		return (NULL);
	it = lst;
	while (it->next != NULL)
		it = it->next;
	return (it);
}
