/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:04:27 by afaby             #+#    #+#             */
/*   Updated: 2022/07/04 11:04:28 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	char		*cmd_path;
	t_builtins	builtin;

	delete_handler();
	if (cmd->node->left->value)
		redirect_check(cmd);
	if (cmd->infile >= 0)
		dup2(cmd->infile, 0);
	if (cmd->outfile >= 0)
		dup2(cmd->outfile, 1);
	builtin = get_builtins(cmd);
	if (builtin.name)
		exec_builtin(cmd, builtin);
	cmd_path = get_cmd(cmd);
	if (!cmd_path)
		command_not_found(cmd);
	if (cmd->infile >= 0)
		close(cmd->infile);
	if (cmd->outfile >= 0)
		close(cmd->outfile);
	execve(cmd_path, cmd->node->right->value, cmd->data->env);
}

/*
* -------------------------
* Function: 
* ------------------------- 
*
*	begin child process
*
* Params:
*	t_cmd	*cmd	: cmd struct
*	t_node	*it		: iterative node
*
* -------------------------
*/
void	start_child(t_cmd *cmd, t_node *it)
{
	int	index;

	index = -1;
	while (++index < cmd->nb_cmd)
	{
		cmd->node = it->left;
		cmd->id = index;
		cmd->pids[index] = fork();
		if (cmd->pids[index] < 0)
			return ;
		if (cmd->pids[index] == 0)
			if (cmd->node->left->value)
				redirect_check(cmd);
		if (index == 0 && cmd->pids[index] == 0)
			first_child(cmd);
		else if (index == cmd->nb_cmd - 1 && cmd->pids[index] == 0)
			last_child(cmd);
		else if (cmd->pids[index] == 0)
			mid_child(cmd);
		it = it->right;
	}
}

/*
* -------------------------
* Function:  first_child
* ------------------------- 
*
*	exec first child
*
* Params:
*	t_cmd	*cmd	: cmd struct
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
	if (cmd->outfile >= 0)
		dup2(cmd->outfile, 1);
	builtin = get_builtins(cmd);
	if (builtin.name)
		exec_builtin(cmd, builtin);
	cmd_path = get_cmd(cmd);
	if (!cmd_path)
		command_not_found(cmd);
	if (cmd->infile >= 0)
		close(cmd->infile);
	if (cmd->outfile >= 0)
		close(cmd->outfile);
	execve(cmd_path, cmd->node->right->value, cmd->data->env);
}

/*
* -------------------------
* Function: mid_child
* ------------------------- 
*
*	exec middle child
*
* Params:
*	t_cmd	*cmd	: cmd struct
*
* -------------------------
*/
void	mid_child(t_cmd *cmd)
{
	char		*cmd_path;
	t_builtins	builtin;

	delete_handler();
	waitpid(cmd->pids[cmd->id - 1], &cmd->data->status, 0);
	close_pipe(cmd, cmd->id);
	dup2(cmd->pipe[cmd->id - 1][0], 0);
	dup2(cmd->pipe[cmd->id][1], 1);
	if (cmd->infile >= 0)
		dup2(cmd->infile, 0);
	if (cmd->outfile >= 0)
		dup2(cmd->outfile, 0);
	builtin = get_builtins(cmd);
	if (builtin.name)
		exec_builtin(cmd, builtin);
	cmd_path = get_cmd(cmd);
	if (!cmd_path)
		command_not_found(cmd);
	if (cmd->infile >= 0)
		close(cmd->infile);
	if (cmd->outfile >= 0)
		close(cmd->outfile);
	execve(cmd_path, cmd->node->right->value, cmd->data->env);
}

/*
* -------------------------
* Function: last_child
* ------------------------- 
*
*	exec last child
*
* Params:
*	t_cmd	*cmd	: cmd struct
*
* -------------------------
*/
void	last_child(t_cmd *cmd)
{
	char		*cmd_path;
	t_builtins	builtin;

	delete_handler();
	waitpid(cmd->pids[cmd->id - 1], &cmd->data->status, 0);
	close_pipe(cmd, cmd->id);
	dup2(cmd->pipe[cmd->id - 1][0], 0);
	if (cmd->infile >= 0)
		dup2(cmd->infile, 0);
	if (cmd->outfile >= 0)
		dup2(cmd->outfile, 1);
	builtin = get_builtins(cmd);
	if (builtin.name)
		exec_builtin(cmd, builtin);
	cmd_path = get_cmd(cmd);
	if (!cmd_path)
		command_not_found(cmd);
	if (cmd->infile >= 0)
		close(cmd->infile);
	if (cmd->outfile >= 0)
		close(cmd->outfile);
	execve(cmd_path, cmd->node->right->value, cmd->data->env);
}
