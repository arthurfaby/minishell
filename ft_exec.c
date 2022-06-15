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
char	*get_cmd(t_data *data, char **envp)
{
	char	*tmp;
	char	*cmd;
	int		index;

	data->envpth = path_finder(envp);
	data->cmdpth = ft_split(data->envpth, ':');
	index = -1;
	while (data->cmdpth[++index])
	{
		tmp = ft_strjoin(data->cmdpth[index], "/");
		cmd = ft_strjoin(tmp, data->args_child[0]);
		free(tmp);
		tmp = NULL;
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		cmd = NULL;
	}
	if (access(data->args_child[0], 0) == 0)
		return (data->args_child[0]);
	return (NULL);
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
void	fill_docfile(char **argv)
{
	char	*line;
	int		heredoc;

	heredoc = open("heredoc", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (heredoc < 0)
		ft_err_msg(strerror(errno));
	write(1, "pipe heredoc>", 13);
	line = get_next_line(0);
	while (ft_strncmp(argv[2], line, ft_strlen(argv[2]))
		|| line[ft_strlen(argv[2])] != '\n')
	{
		write(heredoc, line, ft_strlen(line));
		write(1, "pipe heredoc>", 13);
		line = get_next_line(0);
	}
	close(heredoc);
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
int	get_number_pipe(t_ast *ast)
{
	int		nb_pipe;
	t_node	*it;

	it = ast->root;
	nb_pipe = 0;
	while (it)
	{
		if (it->type == 0)
			nb_pipe++;
		it = it->right;
	}
	return (nb_pipe);
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
t_cmd	*init_cmd(t_data *data)
{
	t_cmd *cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->infile = -1;
	cmd->outfile = -1;
	//cmd->pipe = NULL;
	cmd->pids = NULL;
	cmd->id = -1;
	cmd->data = data;
	cmd->node = NULL;
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
int	get_redirect(t_cmd *cmd)
{
	int		index;

	index = -1;
	while (cmd->node->left->value[++index])
	{
		if (cmd->node->left->value[index][0] == '<'
			&& cmd->node->left->value[index][1] == '<') // double redirect infile
		{
			//Here_doc
			return (1);
		}
		else if (cmd->node->left->value[index][0] == '<') // simple redirect infile
		{
			if (cmd->infile >= 0)
				close(cmd->infile);
			cmd->infile = open(&cmd->node->left->value[index][1], O_RDONLY);
			if (cmd->infile < 0)
			{
				perror(strerror(errno));
				return (1);
			}
		}
		else if (cmd->node->left->value[index][0] == '>') // simple redirect outfile
		{
			if (cmd->outfile >= 0)
				close(cmd->outfile);
			cmd->outfile = open(&cmd->node->left->value[index][1], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
			if (cmd->outfile < 0)
			{
				perror(strerror(errno));
				return (1);
			}
		}
		else if (cmd->node->left->value[index][0] == '>'
			&& cmd->node->left->value[index][1] == '>') // double redirect outfile
		{
			if (cmd->outfile >= 0)
				close(cmd->outfile);
			cmd->outfile = open(&cmd->node->left->value[index][2], O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
			if (cmd->outfile < 0)
			{
				perror(strerror(errno));
				return (1);
			}
		}
	}
	return (0);
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
// Check redirect in ordre
// if infile not found => quit error not found
// if <<EOF then read till EOF even if not last infile
void	simple_child(t_cmd *cmd)
{
	int	ret;

	ret = get_redirect(cmd); // if infile or outfile > -1 then redirect from/on them
	if (ret == 1)//Error redirect
		return ;
	if (cmd->infile >= 0)
		dup2(cmd->infile, 0);
	if (cmd->outfile >= 0)
		dup2(cmd->outfile, 1);
	execve(cmd->node->right->value[0], cmd->node->right->value, cmd->data->envp);
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
void	ft_exec(t_data *data, t_ast *ast)
{
	// Parcourir l'arbre for each command
	// nb_pipe +1 for each pipe
	// init pipe
	// malloc pid_t pids[nb_command]
	// fork childs
	// close properly unused pipe
	// waitpids
	t_cmd	*cmd;
	t_node	*it;
	int		status;

	cmd = init_cmd(data);
	if (!cmd)
		return ;
	it = ast->root;
	if (it->type != 0)
	{
		// Basic command
		cmd->node = it;
		cmd->pids = malloc(sizeof(pid_t));
		if(!cmd->pids)
			return ;//free cmd etc
		cmd->pids[0] = fork();
		if (cmd->pids[0] == 0)
			simple_child(cmd);
		waitpid(cmd->pids[0], &status, 0);
		return ;
	}
	//while (it)
	//{
		// Multiple command with pipe
	//	it = it->right;
	//}
	free(cmd->pids);
	free(cmd);
}
