#include "minishell.h"

int	fill_ast(t_ast *ast, int size)
{
	t_node	*it;

	ast->root = new_node(PIPE, NULL);
	it = ast->root;
	size--;
	while (size--)
	{
		add_right(it, new_node(PIPE, NULL));
		it = it->right;
	}
	return (size);
}

t_ast	*set_unique_cmd(t_ast *ast, char **pipe)
{
	ast->root = new_node(COMMAND, get_content(pipe[0]));
	ft_sstrdel(pipe);
	split_args_redirect(ast);
	return (ast);
}

/*
* -------------------------
* Function: set_multi_cmd 
* ------------------------- 
*
*	set multi cmds in ast
*
* Params:
*	t_ast	*ast : ast
*
*
* Returns:
*
*
* -------------------------
*/
void	set_multi_cmd(t_ast *ast, char **pipe)
{
	int		size;
	t_node	*it;

	size = 0;
	it = ast->root;
	while (pipe[size])
	{
		add_left(it, new_node(COMMAND, get_content(pipe[size])));
		it = it->right;
		size++;
	}
}

/*
* -------------------------
* Function: tokenizer
* ------------------------- 
*
*	tokenize the parsed string
*
* Params:
*	char *cmd	: command parsed
*	t_ast *ast	: AST of the command
*
* Returns:
*	t_ast *ast	: tokenized command
*
* -------------------------
*/
t_ast	*tokenizer(char *cmd, t_ast *ast)
{
	int		size;
	char	**pipe;

	ast = malloc(sizeof(t_ast));
	if (!ast)
		return (NULL);
	pipe = ft_split(cmd, '|');
	if (!pipe)
		return (free(ast), NULL);
	size = 0;
	while (pipe[size])
		size++;
	if (size > 1)
		size = fill_ast(ast, size);
	/*{
		ast->root = new_node(PIPE, NULL);
		it = ast->root;
		size--;
		while (size--)
		{
			add_right(it, new_node(PIPE, NULL));
			it = it->right;
		}
	}*/
	if (size == 1)
		return (set_unique_cmd(ast, pipe));
	/*{
		ast->root = new_node(COMMAND, get_content(pipe[0]));
		ft_sstrdel(pipe);
		split_args_redirect(ast);
		return (ast);
	}*/
	set_multi_cmd(ast, pipe);
	/*size = 0;
	it = ast->root;
	while (pipe[size])
	{
		add_left(it, new_node(COMMAND, get_content(pipe[size])));
		it = it->right;
		size++;
	}*/
	ft_sstrdel(pipe);
	split_args_redirect(ast);
	return (ast);
}

/*
* -------------------------
* Function: split_args_redirect
* ------------------------- 
*
*	split commands into redirections and args
*
* Params:
*	t_ast *ast	: AST of commands
*
* -------------------------
*/
void	split_args_redirect(t_ast *ast)
{
	t_node	*it;
	char	**split;
	char	**args;
	char	**redirect;

	it = ast->root;
	while (it)
	{
		if (it->type != 0)
		{
			split = ft_split(it->value[0], ' ');
			args = get_split_args(split, args);
			redirect = get_split_redirect(split, redirect);
			it->left = new_node(REDIRECTION, ft_sstrdup(redirect));
			it->right = new_node(ARGS, ft_sstrdup(args));
			free_trio(split, args, redirect);
			break ;
		}
		split = ft_split(it->left->value[0], ' ');
		args = get_split_args(split, args);
		redirect = get_split_redirect(split, redirect);
		it->left->left = new_node(REDIRECTION, ft_sstrdup(redirect));
		it->left->right = new_node(ARGS, ft_sstrdup(args));
		it = it->right;
		free_trio(split, args, redirect);
	}
}
