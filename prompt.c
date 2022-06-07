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
	int		i;

	line = readline(PROMPT);
	while (line)
	{
		if (*line)
		{
			add_history(line);
			if (ft_strcmp(line, "exit") == 0)
				break ;
			else if (ft_strcmp(line, "env") == 0)
				ft_env(data);
			else if (ft_strnstr(line, "export", 6))
			{
				i = 0;
				while (line[i] && line[i] != ' ')
					i++;
				add_env(line + i + 1, data);
			}
			else if (ft_strnstr(line, "unset", 5))
			{
				i = 0;
				while (line[i] && line[i] != ' ')
					i++;
				remove_env(line + i + 1, data);
			}
			else if (!parser(data, line))
				exec_cmd(data);
		}
		free(line);
		line = NULL;
		free_cmd_stack(data);
		line = readline(PROMPT);
	}
	rl_clear_history();
	free(line);
	line = NULL;
}
