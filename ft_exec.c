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
	path = ft_split(get_env_value(cmd->data, "PATH"), ':');
	if (!path)
		return (NULL);
	while (path[++index])
	{
		tmp = ft_strjoin(cmd->data->path[index], "/");
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
* Function: get_number_pipe
* ------------------------- 
*
*	return the number of pipe in command AST
*
* Params:
*	t_ast *ast	: AST from command
*
* Returns:
*	int nb_pipe	: number of pipe
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
t_cmd	*init_cmd(t_data *data)
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
	cmd->data = data;
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
int	fill_docfile(char *eof)
{
	char	*line;
	int		heredoc;

	heredoc = open("heredoc", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (heredoc < 0)
		return (0);
	write(1, "heredoc> ", 9);
	line = get_next_line(0);
	while (ft_strncmp(eof, line, ft_strlen(eof))
		|| line[ft_strlen(eof)] != '\n')
	{
		write(heredoc, line, ft_strlen(line));
		free(line);
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
	}
	free(line);
	close(heredoc);
	return (1);
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
int	get_input_redirect(t_cmd *cmd, int index)
{
	if (cmd->node->left->value[index][0] == '<'
		&& cmd->node->left->value[index][1] == '<')
	{
		if (cmd->infile >= 0)
			close(cmd->infile);
		if (!fill_docfile(cmd->node->left->value[index] + 2))
			return (1);
		cmd->infile = open("heredoc", O_RDONLY);
		if (cmd->infile < 0)
		{
			perror(strerror(errno));
			return (1);
		}
	}
	else if (cmd->node->left->value[index][0] == '<')
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
int	get_output_redirect(t_cmd *cmd, int index)
{
	if (cmd->node->left->value[index][0] == '>'
		&& cmd->node->left->value[index][1] == '>')
	{
		if (cmd->outfile >= 0)
			close(cmd->outfile);
		cmd->outfile = open(&cmd->node->left->value[index][2],
				O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
		if (cmd->outfile < 0)
		{
			perror(strerror(errno));
			return (1);
		}
	}
	else if (cmd->node->left->value[index][0] == '>')
	{
		if (cmd->outfile >= 0)
			close(cmd->outfile);
		cmd->outfile = open(&cmd->node->left->value[index][1],
				O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
		if (cmd->outfile < 0)
		{
			perror(strerror(errno));
			return (1);
		}
	}
	return (0);
}

/*
* -------------------------
* Function: get_redirect
* ------------------------- 
*
*	Open redirections files until last one
*
* Params:
*	t_cmd *cmd	: cmd struct
*
* Returns:
*	int (1)	: error redirections files
*	int (0)	: redirections opened
*
* -------------------------
*/
int	get_redirect(t_cmd *cmd)
{
	int		index;

	index = -1;
	while (cmd->node->left->value[++index])
	{
		if (get_input_redirect(cmd, index))
			return (1);
		if (get_output_redirect(cmd, index))
			return (1);
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
t_builtins	get_builtins(t_cmd *cmd)
{
	int	index;

	index = 0;
	while (cmd->data->builtins[index].name
		&& !ft_strstr(cmd->data->builtins[index].name,
			cmd->node->right->value[0]))
		index++;
	return (cmd->data->builtins[index]);
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
* Function: simple_child
* ------------------------- 
*
*	child process function if only one command in user input
*
* Params:
*	t_cmd *cmd	: cmd struct
*
* -------------------------
*/
void	simple_child(t_cmd *cmd)
{
	int			ret;
	char		*cmd_path;
	t_builtins	builtin;

	delete_handler();
	if (cmd->node->left->value)
	{
		ret = get_redirect(cmd);
		if (ret == 1)
			exit(-5);// Error code redirection error ?
	}
	if (cmd->infile >= 0)
		dup2(cmd->infile, 0);
	if (cmd->outfile >= 0)
		dup2(cmd->outfile, 1);
	builtin = get_builtins(cmd);
	if (builtin.name)
	{
		cmd_path = NULL;
		cmd_path = join_cmd(cmd->node->right->value, cmd_path);
		if (!cmd_path)
			exit(-2);//error builtin
		builtin.builtin(cmd->data, cmd_path);
		free(cmd_path);
		exit(cmd->data->status);
	}
	cmd_path = get_cmd(cmd);
	if (!cmd_path)
	{
		perror(CMD_NOT_FOUND);
		exit(-1);
	}
	execve(cmd_path, cmd->node->right->value, cmd->data->env);
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
void	open_pipe(t_cmd *cmd)
{
	int	index;

	index = -1;
	while (++index < cmd->nb_cmd - 1)
	{
		cmd->pipe[index] = malloc(sizeof(int) * 2);
		if (!cmd->pipe[index])
			return ;// malloc error free clean
		if (pipe(cmd->pipe[index]) < 0)
			return ;// Error opening pipe + free clean
	}
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
void	close_pipe(t_cmd *cmd, int id)
{
	int	index;

	index = -1;
	while (++index < cmd->nb_cmd - 1)
	{
		if (id == 0 && index == 0)
			close(cmd->pipe[index][0]);
		else if (id == cmd->nb_cmd - 1 && index == cmd->nb_cmd - 2)
			close(cmd->pipe[index][1]);
		else if (id == 0 || id == cmd->nb_cmd - 1)
		{
			close(cmd->pipe[index][0]);
			close(cmd->pipe[index][1]);
		}
		else if (index == id - 1)
			close(cmd->pipe[index][1]);
		else if (index == id)
			close(cmd->pipe[index][0]);
		else
		{
			close(cmd->pipe[index][0]);
			close(cmd->pipe[index][1]);
		}
	}
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
void	exec_multiple_cmd(t_ast *ast, t_cmd *cmd)
{
	// get number of commands
	// create number oof commands - 1 pipe
	// launch childs process
	// close every pipe
	t_node	*it;
	int		index;
	int		ret;

	it = ast->root;
	while (it)
	{
		cmd->nb_cmd++;
		it = it->right;
	}
	cmd->pids = malloc(sizeof(pid_t) * cmd->nb_cmd);
	if (!cmd->pids)
		return ; // free clean
	cmd->pipe = malloc(sizeof(int *) * cmd->nb_cmd - 1);
	if (!cmd->pipe)
		return ; // free clean
	open_pipe(cmd);
	it = ast->root;
	index = -1;
	while (++index < cmd->nb_cmd)
	{
		cmd->node = it->left;
		cmd->id = index;
		if (cmd->node->left->value)
		{
			ret = get_redirect(cmd);
			if (ret == 1)
				return ;//(-5) Error redirect code ?
		}
		cmd->pids[index] = fork();
		if (cmd->pids[index] < 0)
			return ; // Error fork + free clean
		else if (index == 0 && cmd->pids[index] == 0)
			first_child(cmd);
		else if (index == cmd->nb_cmd - 1 && cmd->pids[index] == 0)
			last_child(cmd);
		else if (cmd->pids[index] == 0)
			mid_child(cmd);
		it = it->right;
	}
	close_pipe(cmd, -42);
	index = -1;
	while (++index < cmd->nb_cmd)
		waitpid(cmd->pids[index], &cmd->data->status, 0);
	// if << in redirect then unlink
	unlink("heredoc");
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
void	free_pipe(t_cmd *cmd)
{
	int	index;

	index = -1;
	while (++index < cmd->nb_cmd - 1)
		free(cmd->pipe[index]);
	free(cmd->pipe);
}

/*
* -------------------------
* Function: ft_exec
* ------------------------- 
*
*	Start child process
*
* Params:
*	t_data *data	: data struct
*	t_ast *ast		: ast struct
*
* -------------------------
*/
void	ft_exec(t_data *data, t_ast *ast)
{
	t_cmd	*cmd;
	t_node	*it;

	cmd = init_cmd(data);
	if (!cmd || !ast->root)
		return ;
	it = ast->root;
	if (it->type != PIPE)
	{
		// Basic command
		cmd->node = it;
		cmd->pids = malloc(sizeof(pid_t));
		if(!cmd->pids)
			return ;//free cmd etc
		ignore_handler();
		cmd->pids[0] = fork();
		if (cmd->pids[0] < 0)
			return ; //free cmd etc
		if (cmd->pids[0] == 0)
			simple_child(cmd);
		waitpid(cmd->pids[0], &data->status, 0);
		message_signal(data->status);
		free(cmd->pids);
		free(cmd);
		create_handler();
		return ;
	}
	// Multiple command with pipe
	ignore_handler();
	exec_multiple_cmd(ast, cmd);
	free_pipe(cmd);
	free(cmd->pids);
	free(cmd);
	create_handler();
}
