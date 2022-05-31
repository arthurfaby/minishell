/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 08:00:53 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:04:31 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*it;

	if (*lst == NULL)
		*lst = new;
	else
	{
		it = *lst;
		while (it->next != NULL)
			it = it->next;
		it->next = new;
	}
}
