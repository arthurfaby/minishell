#include "minishell.h"

void	print_ast(t_ast *ast)
{
	t_node	*it;

	it = ast->root;
	while (it)
	{
		ft_printf("type parent = %d\n", it->type);
		if (it->left)
			ft_printf("type left = %d\n", it->left->type);
		it = it->right;
	}
}

void	free_ast(t_ast *ast)
{
	t_node	*it;
	t_node	*tmp;

	it = ast->root;
	while (it)
	{
		tmp = it;
		if (it->left)
		{
			free(it->left);
			it->left = NULL;
		}
		it = it->right;
		free(tmp);
		tmp = NULL;
	}
	ast->root = NULL;
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
			else if (ft_strnstr(line, "export", 7))
			{
				i = 0;
				while (line[i] && line[i] != ' ')
					i++;
				add_env(data, line + i + 1);
				//ft_printf("%s\n", get_env_value(data, line + i + 1));
			}
			else if (ft_strnstr(line, "unset", 6))
			{
				i = 0;
				while (line[i] && line[i] != ' ')
					i++;
				remove_env(data, line + i + 1);
			}
			else if (ft_strnstr(line, "cd", 3))
			{
				i = 0;
				while (line[i] && line[i] != ' ')
					i++;
				ft_cd(line + i + 1, data);
			}
			else if (ft_strnstr(line, "pwd", 4))
				ft_pwd(data);
			else if (ft_strnstr(line, "ls", 3))
			{
				char	**tes;
				tes = malloc(16);
				tes[0] = "/usr/bin/ls";
				tes[1] = 0;
				execve("/usr/bin/ls", tes, data->envp); 
			}
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
