#include "minishell.h"

/*
* -------------------------
* Function: free_node
* ------------------------- 
*
*	free t_node element
*
* Params:
*	t_node *node	: node to free
*
* -------------------------
*/
void	free_node(t_node *node)
{
	if (!node)
		return ;
	if (node->left)
	{
		free(node->left);
		node->left = NULL;
	}
	if (node->right)
	{
		free(node->right);
		node->right = NULL;
	}
	if (node->value)
	{
		ft_sstrdel(node->value);
		node->value = NULL;
	}
	free(node);
	node = NULL;
}

/*
* -------------------------
* Function: free_ast
* ------------------------- 
*
*	free t_ast element
*
* Params:
*	t_ast *ast	: ast to free
*
* -------------------------
*/
void	free_ast(t_ast *ast)
{
	t_node	*it;
	t_node	*tmp;

	it = ast->root;
	while (it)
	{
		if (it->type == 1)
		{
			free_node(it);
			it = NULL;
		}
		else
		{
			tmp = it;
			free_node(tmp->left);
			it = it->right;
			free(tmp);
			tmp = NULL;
		}
	}
	ast->root = NULL;
}

/*
* -------------------------
* Function: display_prompt
* ------------------------- 
*
*	display minishell prompt
*
* Params:
*	t_data *data	: data from the minishell
*
* -------------------------
*/
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
			else if (ft_strcmp(line, "env") == 0)
				ft_env(data);
			else if (ft_strnstr(line, "export", 6))
				ft_export(data, line);
			else if (ft_strnstr(line, "unset", 5))
				ft_unset(data, line);
			cmd = parser(line);
			ast = tokenizer(cmd, ast);
			free(cmd);
			cmd = NULL;
		}
		free(line);
		line = NULL;
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
