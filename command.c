/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:39:54 by vnaud             #+#    #+#             */
/*   Updated: 2022/06/01 09:57:53 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_elem	*new_elem(char *elem)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	new->id = 0;
	new->cmd = cmd;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_elem_cmd(t_data *data, char *elem)
{
	t_elem	*new;
	t_elem	*it;

	if (!data->cmd->head)
	{
		data->cmd->head = new_elem(elem);
	}
	else
	{
		it = data->elem->head;
		new = new_elem(elem);
		while (it->next)
			it = it->next;
		it->next = new;
		new->prev = it;
		new->id = it->id + 1;
	}
	data->cmd->size++;
}

void	free_cmd(t_data *data)
{
	t_elem	*it;
	t_elem	*tmp;

	it = data->cmd->head;
	while (it)
	{
		tmp = it;
		it = it->next;
		free(tmp);
		tmp = NULL;
	}
	data->cmd->size = 0;
}
