#include "minishell.h"

t_elem	*new_elem(char *elem, int type)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		return (NULL);
	new->id = 0;
	new->type = type;
	new->value = elem;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_elem_cmd(t_data *data, t_elem *new)
{
	t_elem	*it;

	if (!data->cmd->head)
		data->cmd->head = new;
	else
	{
		it = data->cmd->head;
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
	data->cmd->head = NULL;
}
