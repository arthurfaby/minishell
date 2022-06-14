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
void	first_child(t_data *data, char **argv, char **envp, int id)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile < 0)
	{
		free_main(data);
		ft_err_msg(strerror(errno));
	}
	close_pipe(data, id);
	dup2(data->pp[id][1], 1);
	dup2(data->infile, 0);
	data->args_child = ft_split(argv[2], ' ');
	data->cmd = get_cmd(data, envp);
	if (!data->cmd)
	{
		free_child(data, 1);
		ft_err_msg("Error: command not found");
	}
	execve(data->cmd, data->args_child, envp);
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
void	mid_child(t_data *data, char **argv, char **envp, int id)
{
	int		status;

	waitpid(data->child_pid[id - 1], &status, 0);
	close_pipe(data, id);
	dup2(data->pp[id][1], 1);
	dup2(data->pp[id - 1][0], 0);
	data->args_child = ft_split(argv[id + 2], ' ');
	data->cmd = get_cmd(data, envp);
	if (!data->cmd)
	{
		free_child(data, 2);
		ft_err_msg("Error: command not found");
	}
	execve(data->cmd, data->args_child, envp);
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
void	last_child(t_data *data, char **argv, char **envp, int id)
{
	int		status;

	data->outfile = open(argv[data->nb_cmd + 2], 00001101, S_IWUSR | S_IRUSR);
	if (data->outfile < 0)
	{
		free_main(data);
		ft_err_msg(strerror(errno));
	}
	waitpid(data->child_pid[id - 1], &status, 0);
	close_pipe(data, id);
	dup2(data->outfile, 1);
	dup2(data->pp[id - 1][0], 0);
	data->args_child = ft_split(argv[id + 2], ' ');
	data->cmd = get_cmd(data, envp);
	if (!data->cmd)
	{
		free_child(data, 3);
		ft_err_msg("Error: command not found");
	}
	execve(data->cmd, data->args_child, envp);
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
void	create_child(t_data *data, char **argv, char **envp)
{
	int	index;

	index = -1;
	while (++index < data->nb_cmd)
	{
		data->child_pid[index] = fork();
		if (data->child_pid[index] < 0)
			ft_err_msg(strerror(errno));
		else if (index == 0 && data->child_pid[index] == 0)
			first_child(data, argv, envp, index);
		else if (index == data->nb_cmd - 1 && data->child_pid[index] == 0)
			last_child(data, argv, envp, index);
		else if (data->child_pid[index] == 0)
			mid_child(data, argv, envp, index);
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
t_cmd	*init_cmd(t_cmd *cmd, t_data *data)
{
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
// Check redirect in ordre
// if infile not found => quit error not found
// if <<EOF then read till EOF even if not last infile
void	simple_child(t_cmd *cmd)
{
	int		index;

	index = -1;
	while (cmd->node->left->value[++index])
	{
		if (cmd->node->left->value[index][0] == '<'
			&& cmd->node->left->value[index][1] == '<') // double redirect infile
		{
			//Here_doc
		}
		else if (cmd->node->left->value[index][0] == '<') // simple redirect infile
		{
			if (cmd->infile >= 0)
				close(cmd->infile);
			cmd->infile = open(&cmd->node->left->value[index][1], O_RDONLY);
			if (cmd->infile < 0)
			{
				perror(strerror(errno));
				return ;
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
				return ;
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
				return ;
			}
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
void	ft_exec(t-data *data, t_ast *ast)
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

	cmd = init_cmd(cmd, data);
	if (!cmd)
		return ;
	it = ast->root;
	if (it->type != 0)
	{
		// Basic command
		return ;
	}
	while (it)
	{
		// Multiple command with pipe
		it = it->right;
	}
}
