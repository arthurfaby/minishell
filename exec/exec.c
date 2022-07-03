#include "minishell.h"

void	exec_simple_command(t_cmd *cmd, t_node *it)
{
	cmd->node = it;
	cmd->pids = malloc(sizeof(pid_t));
	if (!cmd->pids)
		return ;
	ignore_handler();
	cmd->pids[0] = fork();
	if (cmd->pids[0] < 0)
		return ;
	if (cmd->pids[0] == 0)
		simple_child(cmd);
	waitpid(cmd->pids[0], &g_data->status, 0);
	message_signal(g_data->status);
	free(cmd->pids);
	free(cmd);
	create_handler();
	convert_signal();
	return ;
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
void	ft_exec(t_ast *ast)
{
	t_cmd	*cmd;
	t_node	*it;

	cmd = init_cmd();
	if (!cmd || !ast->root)
		return ;
	it = ast->root;
	if (it->type != PIPE)
		exec_simple_command(cmd, it);
	else
	{
		ignore_handler();
		exec_multiple_cmd(ast, cmd);
		free_pipe(cmd);
		free(cmd->pids);
		free(cmd);
		create_handler();
		convert_signal();
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
	t_node	*it;
	int		index;

	get_nb_cmd(ast, cmd);
	cmd->pids = malloc(sizeof(pid_t) * cmd->nb_cmd);
	if (!cmd->pids)
		return ;
	cmd->pipe = malloc(sizeof(int *) * cmd->nb_cmd - 1);
	if (!cmd->pipe)
		return ;
	open_pipe(cmd);
	it = ast->root;
	start_child(cmd, it);
	close_pipe(cmd, -42);
	index = -1;
	while (++index < cmd->nb_cmd)
	{
		waitpid(cmd->pids[index], &cmd->data->status, 0);
		message_signal(cmd->data->status);
	}
	unlink("heredoc");
}
