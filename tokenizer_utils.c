#include "minishell.h"

char	**free_before(char **args, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(args[size]);
		args[size] = NULL;
		i++;
	}
	free(args);
	return (NULL);
}

void	free_trio(char **split, char **args, char **redirect)
{
	ft_sstrdel(split);
	ft_sstrdel(args);
	ft_sstrdel(redirect);
}

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
	if (!args || size == 0)
		return (free(args), NULL);
	args[size] = NULL;
	index = -1;
	size = 0;
	while (split[++index])
	{
		if (split[index][0] != '<' && split[index][0] != '>')
		{
			args[size] = ft_strdup(split[index]);
			if (!args[size])
				return (free_before(args, size));
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
	if (!redirect || size == 0)
		return (free(redirect), NULL);
	redirect[size] = NULL;
	index = -1;
	size = 0;
	while (split[++index])
	{
		if (split[index][0] == '<' || split[index][0] == '>')
		{
			redirect[size] = ft_strdup(split[index]);
			if (!redirect[size])
				return (free_before(redirect, size));
			size++;
		}
	}
	return (redirect);
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
