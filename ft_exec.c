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

	if (access(cmd->node->right->value[0], F_OK | X_OK) == 0)
		return (cmd->node->right->value[0]);
	index = -1;
	while (cmd->data->path[++index])
	{
		tmp = ft_strjoin(cmd->data->path[index], "/");
		cmd_tmp = ft_strjoin(tmp, cmd->node->right->value[0]);
		free(tmp);
		tmp = NULL;
		if (access(cmd_tmp, F_OK | X_OK) == 0)
			return (cmd_tmp);
		free(cmd_tmp);
		cmd_tmp = NULL;
	}
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
/*void	fill_docfile(char **argv)
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
}*/

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
		if (cmd->node->left->value[index][0] == '<'
			&& cmd->node->left->value[index][1] == '<')
		{
			//Here_doc
			return (1);
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
		else if (cmd->node->left->value[index][0] == '>')
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
			&& cmd->node->left->value[index][1] == '>')
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
// Check redirect in ordre
// if infile not found => quit error not found
// if <<EOF then read till EOF even if not last infile
void	simple_child(t_cmd *cmd)
{
	int		ret;
	char	*cmd_path;

	delete_handler();
	if (cmd->node->left->value)
	{
		ret = get_redirect(cmd);
		if (ret == 1)//Error redirect : message ?
			return ;
	}
	if (cmd->infile >= 0)
		dup2(cmd->infile, 0);
	if (cmd->outfile >= 0)
		dup2(cmd->outfile, 1);
	cmd_path = get_cmd(cmd);
	if (!cmd_path)
	{
		perror(CMD_NOT_FOUND);
		exit(-1);
	}
	execve(cmd_path, cmd->node->right->value, cmd->data->envp);
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

	status = 0;
	cmd = init_cmd(data);
	if (!cmd)
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
		waitpid(cmd->pids[0], &status, 0);
		message_signal(status);
		create_handler();
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
