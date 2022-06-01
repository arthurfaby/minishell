/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:39:54 by vnaud             #+#    #+#             */
/*   Updated: 2022/06/01 09:25:00 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*new_cmd(char *cmd)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	new->id = 0;
	new->cmd = cmd;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_cmd_history(t_data *data, char *cmd)
{
	t_cmd	*new;
	t_cmd	*it;

	if (!data->history->head)
	{
		data->history->head = new_cmd(cmd);
		data->history->size++;
	}
	else
	{
		it = data->history->head;
		new = new_cmd(cmd);
		new->next = it;
		it->prev = new;
		while (it->next)
		{
			it->id = it->id + 1;
			it = it->next;
		}
		it->id = it->id + 1;
		if (it->id >= data->history->max)
			del_last_history(data);
		else
			data->history->size++;
	}
}

void	del_last_history(t_data *data)
{
	t_cmd	*it;

	it = data->history->head;
	if (it)
	{
		while (it->next)
			it = it->next;
		it->prev->next = NULL;
		free(it);
		it = NULL;
	}
}

void	free_history(t_data *data)
{
	t_cmd	*it;
	t_cmd	*tmp;

	it = data->history->head;
	while (it)
	{
		tmp = it;
		it = it->next;
		free(tmp);
		tmp = NULL;
	}
	data->history->size = 0;
}
