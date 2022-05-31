/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 08:10:20 by vnaud             #+#    #+#             */
/*   Updated: 2022/04/21 22:05:19 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*it;
	t_list	*new;
	t_list	*res;

	if (f == NULL)
		return (NULL);
	res = NULL;
	it = lst;
	while (it)
	{
		new = ft_lstnew((*f)(it->content));
		if (new == NULL)
		{
			ft_lstclear(&res, del);
			return (res);
		}
		ft_lstadd_back(&res, new);
		it = it->next;
	}
	return (res);
}
