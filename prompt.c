#include "minishell.h"

void	print_ast(t_ast *ast)
{
	t_node	*it;

	it = ast->root;
	while (it)
	{
		if (it->type == 0)
		{
			ft_printf("type parent = %d\n", it->type);
			if (it->left)
			{
				ft_printf("type left = %d\n", it->left->type);
				ft_printf("content left = %s\n", it->left->value[0]);
			if (it->left->left)
				ft_printf("content redirect = %s\n", it->left->left->value[0]);
			if (it->left->right)
				ft_printf("content args = %s\n", it->left->right->value[0]);
			}
		}
		else
		{
			ft_printf("type elem = %d\n", it->type);
			ft_printf("content elem = %s\n", it->value[0]);
			if (it->left)
				ft_printf("content redirect = %s\n", it->left->value[0]);
			if (it->right)
				ft_printf("content args = %s\n", it->right->value[0]);
		}
		it = it->right;
	}
}

void	free_node(t_node *node)
{
	if (node->left)
	if (node->right)
	if (node->value)
	free(node);
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
	char	*cmd;
	t_ast	*ast;

	ast = malloc(sizeof(t_ast));
	if (!ast)
		return ;
	ast->root = NULL;
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
			cmd = parser(line);
			ast = tokenizer(cmd, ast);
			print_ast(ast);
			free(cmd);
			cmd = NULL;
			//exec_cmd(data);
		}
		free(line);
		line = NULL;
		free_cmd_stack(data);
		free_ast(ast);
		line = readline(PROMPT);
	}
	rl_clear_history();
	free(line);
	line = NULL;
	free_ast(ast);
	free(ast);
	ast = NULL;
}
