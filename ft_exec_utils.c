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
void	first_child(t_cmd *cmd)
{
	char		*cmd_path;
	t_builtins	builtin;

	delete_handler();
	close_pipe(cmd, cmd->id);
	if (cmd->infile >= 0)
		dup2(cmd->infile, 0);
	dup2(cmd->pipe[cmd->id][1], 1);
	builtin = get_builtins(cmd);
	if (builtin.name)//join every part of value to a single string
	{
		builtin.builtin(cmd->data, cmd->node->right->value[0]);
		exit(cmd->data->status);
	}
	cmd_path = get_cmd(cmd);
	if (!cmd_path)
	{
		ft_putstr_fd(cmd->node->right->value[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(-1);
	}
	if (cmd->infile >= 0)
		close(cmd->infile);
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
void	mid_child(t_cmd *cmd)
{
	char	*cmd_path;
	t_builtins	builtin;

	delete_handler();
	waitpid(cmd->pids[cmd->id - 1], &cmd->data->status, 0);
	close_pipe(cmd, cmd->id);
	dup2(cmd->pipe[cmd->id - 1][0], 0);
	dup2(cmd->pipe[cmd->id][1], 1);
	builtin = get_builtins(cmd);
	if (builtin.name)//join every part of value to a single string
	{
		builtin.builtin(cmd->data, cmd->node->right->value[0]);
		exit(cmd->data->status);
	}
	cmd_path = get_cmd(cmd);
	if (!cmd_path)
	{
		ft_putstr_fd(cmd->node->right->value[0], 2);
		ft_putstr_fd(": command not found\n", 2);
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
void	last_child(t_cmd *cmd)
{
	char	*cmd_path;
	t_builtins	builtin;

	delete_handler();
	waitpid(cmd->pids[cmd->id - 1], &cmd->data->status, 0);
	close_pipe(cmd, cmd->id);
	if (cmd->outfile >= 0)
		dup2(cmd->outfile, 1);
	dup2(cmd->pipe[cmd->id - 1][0], 0);
	builtin = get_builtins(cmd);
	if (builtin.name)//join every part of value to a single string
	{
		builtin.builtin(cmd->data, cmd->node->right->value[0]);
		exit(cmd->data->status);
	}
	cmd_path = get_cmd(cmd);
	if (!cmd_path)
	{
		ft_putstr_fd(cmd->node->right->value[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(-1);
	}
	if (cmd->outfile >= 0)
		close(cmd->outfile);
	execve(cmd_path, cmd->node->right->value, cmd->data->env);
}
