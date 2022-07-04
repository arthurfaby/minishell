#include "minishell.h"

/*
* -------------------------
* Function: skip_whitespace
* ------------------------- 
*
*	get index after whitespaces in cmd
*
* Params:
*	char *cmd		: command line
*	int index_start	: index to start search of whitespaces
*
* Returns:
*	int index		: index after whitespaces
*
* -------------------------
*/
int	skip_whitespace(char *cmd, int index_start)
{
	while (cmd[index_start] && ft_iswhitespace(cmd[index_start]))
		index_start++;
	return (index_start);
}

void	get_size_spaces_redirections(char *cmd, int *size)
{
	int	index;

	index = -1;
	while (cmd[++index])
	{
		if (cmd[index] == '<' || cmd[index] == '>')
		{
			if (cmd[index + 1] == ' ')
				(*size)--;
		}
		else if ((cmd[index] == '<' && cmd[index + 1] == '<')
			|| (cmd[index] == '>' && cmd[index + 1] == '>'))
		{
			if (cmd[index + 2] == ' ')
				(*size)--;
		}
	}
}

void	remove_spaces_redirections(char *res, char *cmd,
		int *index, int *index_res)
{
	if (cmd[*index] == '<' || cmd[*index] == '>')
	{
		if (cmd[(*index) + 1] == ' ')
			res[(*index_res)++] = cmd[(*index)++];
		else
			res[(*index_res)++] = cmd[*index];
	}
	else if ((cmd[*index] == '<' && cmd[(*index) + 1] == '<')
		|| (cmd[*index] == '>' && cmd[(*index) + 1] == '>'))
	{
		if (cmd[(*index) + 2] == ' ')
		{
			res[(*index_res)++] = cmd[(*index)++];
			res[(*index_res)++] = cmd[(*index)++];
		}
		else
		{
			res[(*index_res)++] = cmd[(*index)++];
			res[(*index_res)++] = cmd[*index];
		}
	}
	else
		res[(*index_res)++] = cmd[*index];
}

/*
* -------------------------
* Function: spaces_redirections
* ------------------------- 
*
*	remove spaces between redirections symbole and filename
*
* Params:
*	char *cmd	: command line
*
* Returns:
*	char *res	: command strip from spaces
*
* -------------------------
*/
char	*spaces_redirections(char *cmd)
{
	int		index;
	int		index_res;
	char	*res;
	int		size;

	if (!cmd || !*cmd)
		return (cmd);
	size = ft_strlen(cmd);
	get_size_spaces_redirections(cmd, &size);
	res = malloc(sizeof(char) * (size + 1));
	index = -1;
	index_res = 0;
	while (cmd[++index])
		remove_spaces_redirections(res, cmd, &index, &index_res);
	free(cmd);
	cmd = NULL;
	res[size] = '\0';
	return (res);
}

int	ft_intlen(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}
