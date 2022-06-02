#include "minishell.h"

void	print_cmd_stack(t_data *data)
{
	t_elem	*it;

	it = data->cmd->head;
	while (it)
	{
		ft_printf("type = %d, id = %d, value = %s\n",
			it->type, it->id, it->value);
		it = it->next;
	}
}

void	free_cmd_stack(t_data *data)
{
	t_elem	*it;
	t_elem	*tmp;

	it = data->cmd->head;
	while (it)
	{
		free(it->value);
		it->value = NULL;
		tmp = it;
		it = it->next;
		free(tmp);
		tmp = NULL;
	}
	data->cmd->head = NULL;
	data->cmd->size = 0;
}

void	display_prompt(t_data *data)
{
	char	*line;

	line = readline("mshell >> ");
	while (line)
	{
		if (*line)
		{
			if (ft_strcmp(line, "exit") == 0)
				break ;
			if (!parser(data, line))
				exec_cmd(data);
		}
		free(line);
		line = NULL;
		free_cmd_stack(data);
		line = readline("mshell >> ");
	}
	free(line);
	line = NULL;
}
