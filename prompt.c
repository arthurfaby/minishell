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
