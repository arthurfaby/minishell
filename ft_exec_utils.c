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
	char	*cmd_path;

	delete_handler();
	close_pipe(cmd, cmd->id);
	if (cmd->infile >= 0)
		dup2(cmd->infile, 0);
	dup2(cmd->pipe[cmd->id][1], 1);
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

	delete_handler();
	waitpid(cmd->pids[cmd->id - 1], &cmd->data->status, 0);
	close_pipe(cmd, cmd->id);
	dup2(cmd->pipe[cmd->id - 1][0], 0);
	dup2(cmd->pipe[cmd->id][1], 1);
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

	delete_handler();
	waitpid(cmd->pids[cmd->id - 1], &cmd->data->status, 0);
	close_pipe(cmd, cmd->id);
	if (cmd->outfile >= 0)
		dup2(cmd->outfile, 1);
	dup2(cmd->pipe[cmd->id - 1][0], 0);
	cmd_path = get_cmd(cmd);
	if (!cmd_path)
	{
		perror(CMD_NOT_FOUND);
		exit(-1);
	}
	execve(cmd_path, cmd->node->right->value, cmd->data->envp);
}
