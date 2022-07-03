#include "minishell.h"

/*
* -------------------------
* Function: get_cmd
* ------------------------- 
*
*	return if the command path exist
*
* Params:
*	t_cmd *cmd	: command struct
*
* Returns:
*	int (1)		: command found
*	int (0)		: command not found
*
* -------------------------
*/
char	*get_cmd(t_cmd *cmd)
{
	char	*tmp;
	char	*cmd_tmp;
	int		index;
	char	**path;

	if (access(cmd->node->right->value[0], F_OK | X_OK) == 0)
		return (cmd->node->right->value[0]);
	index = -1;
	path = ft_split(get_env_value("PATH"), ':');
	if (!path)
		return (NULL);
	while (path[++index])
	{
		tmp = ft_strjoin(path[index], "/");
		cmd_tmp = ft_strjoin(tmp, cmd->node->right->value[0]);
		free(tmp);
		if (access(cmd_tmp, F_OK | X_OK) == 0)
		{
			ft_sstrdel(path);
			return (cmd_tmp);
		}
		free(cmd_tmp);
	}
	ft_sstrdel(path);
	return (NULL);
}

/*
* -------------------------
* Function: init_cmd
* ------------------------- 
*
*	Initialize t_cmd struct
*
* Params:
*	t_data *data	: data struct
*
* Returns:
*	t_cmd *cmd		: cmd struct
*
* -------------------------
*/
t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->infile = -1;
	cmd->outfile = -1;
	cmd->pipe = NULL;
	cmd->pids = NULL;
	cmd->id = -1;
	cmd->data = g_data;
	cmd->node = NULL;
	cmd->nb_cmd = 0;
	return (cmd);
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
char	*join_cmd(char **value, char *cmd)
{
	int	index;
	int	index_str;
	int	size;
	int	index_res;

	index = -1;
	size = 0;
	while (value[++index])
		size += ft_strlen(value[index]);
	size += (index - 1);
	cmd = malloc(sizeof(char) * (size + 1));
	if (!cmd)
		return (NULL);
	index = -1;
	index_res = 0;
	while (value[++index])
	{
		index_str = 0;
		while (value[index][index_str])
			cmd[index_res++] = value[index][index_str++];
		cmd[index_res++] = ' ';
	}
	cmd[--index_res] = '\0';
	return (cmd);
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
void	command_not_found(t_cmd *cmd)
{
	ft_putstr_fd(cmd->node->right->value[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
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
void	get_nb_cmd(t_ast *ast, t_cmd *cmd)
{
	t_node	*it;

	it = ast->root;
	while (it)
	{
		cmd->nb_cmd++;
		it = it->right;
	}
}
