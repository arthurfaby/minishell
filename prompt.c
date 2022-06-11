#include "minishell.h"

/*
* -------------------------
* Function: print_ast
* ------------------------- 
*
*	print elem in the abstract syntax tree
*
* Params:
*	t_ast *ast	: ast from user command line
*
* -------------------------
*/
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
			//print_ast(ast);
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
