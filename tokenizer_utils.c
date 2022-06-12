#include "minishell.h"

/*
* -------------------------
* Function: get_split_args
* ------------------------- 
*
*	create a tab with the command and args
*
* Params:
*	char **split	: command split on spaces
*	char **args		: tab of command and args
*
* Returns:
*	char **args		: tab of command and args
*	char **(NULL)	: malloc error
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
* Function: get_split_redirect
* ------------------------- 
*
*	Create a tab of every redirections of the command
*
* Params:
*	char **split	: command split on spaces
*	char **redirect	: tab of redirections
*
* Returns:
*	char **redirect	: tab of redirections
*	char **(NULL)	: malloc error
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
			ft_sstrdel(split);
			ft_sstrdel(args);
			ft_sstrdel(redirect);
			break ;
		}
		split = ft_split(it->left->value[0], ' ');
		args = get_split_args(split, args);
		redirect = get_split_redirect(split, redirect);
		it->left->left = new_node(REDIRECTION, redirect);
		it->left->right = new_node(ARGS, args);
		it = it->right;
		ft_sstrdel(split);
		ft_sstrdel(args);
		ft_sstrdel(redirect);
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
