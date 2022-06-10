#include "minishell.h"

/*
* -------------------------
* Function: 
* ------------------------- 
*
*
*
* Params:
*
*
* Returns:
*
*
* -------------------------
*/
char	**get_split_args(char **split, char **args)
{
	int	index;
	int	size;

	index = -1;
	size = 0;
	while (split[++index])
		if (split[index][0] != '<' && split[index][0] != '>')
			size++;
	args = malloc(sizeof(char *) * (size + 1));
	if (!args)
		return (NULL);
	args[size] = NULL;
	index = -1;
	size = 0;
	while (split[++index])
	{
		if (split[index][0] != '<' && split[index][0] != '>')
		{
			args[size] =  ft_strdup(split[index]);
			if (!args[size])
				return (NULL); // free all previous args
			size++;
		}
	}
	return (args);
}

/*
* -------------------------
* Function: 
* ------------------------- 
*
*
*
* Params:
*
*
* Returns:
*
*
* -------------------------
*/
char	**get_split_redirect(char **split, char **redirect)
{
	int	index;
	int	size;

	index = -1;
	size = 0;
	while (split[++index])
		if (split[index][0] == '<' || split[index][0] == '>')
			size++;
	redirect = malloc(sizeof(char *) * (size + 1));
	if (!redirect)
		return (NULL);
	redirect[size] = NULL;
	index = -1;
	size = 0;
	while (split[++index])
	{
		if (split[index][0] == '<' || split[index][0] == '>')
		{
			redirect[size] =  ft_strdup(split[index]);
			if (!redirect[size])
				return (NULL); // free all previous and redirect
			size++;
		}
	}
	return (redirect);
}

/*
* -------------------------
* Function: split_args_redirect
* ------------------------- 
*
*	split commands into redirections and args
*
* Params:
*
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
			it->left = new_node(REDIRECTION, redirect);
			it->right = new_node(ARGS, args);
			break ;
		}
		split = ft_split(it->left->value[0], ' ');
		args = get_split_args(split, args);
		redirect = get_split_redirect(split, redirect);
		it->left->left = new_node(REDIRECTION, redirect);
		it->left->right = new_node(ARGS, args);
		it = it->right;
	}
}

/*
* -------------------------
* Function: get_content
* ------------------------- 
*
*	Create a copy of str in char **
*
* Params:
*	char *str	: content string
*
* Returns:
*	char **res	: content in char **
*
* -------------------------
*/
char	**get_content(char *str)
{
	char	**res;

	if (!str)
		return (NULL);
	res = malloc(sizeof(char *) * 2);
	if (!res)
		return (NULL);
	res[0] = ft_strdup(str);
	if (!res[0])
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	res[1] = NULL;
	return (res);
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
	t_node	*it;

	pipe = ft_split(cmd, '|');
	if (!pipe)
		return (NULL);
	size = 0;
	while (pipe[size])
		size++;
	if (size > 1)
	{
		ast->root = new_node(PIPE, NULL);
		it = ast->root;
		size--;
		while (size--)
		{
			add_right(it, new_node(PIPE, NULL));
			it = it->right;
		}
	}
	if (size == 1)
	{
		ast->root = new_node(COMMAND, get_content(pipe[0]));
		ft_sstrdel(pipe);
		split_args_redirect(ast);
		return (ast);
	}
	size = 0;
	it = ast->root;
	while (pipe[size])
	{
		add_left(it, new_node(COMMAND, get_content(pipe[size])));
		it = it->right;
		size++;
	}
	ft_sstrdel(pipe);
	split_args_redirect(ast);
	return (ast);
}
