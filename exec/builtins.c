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
t_builtins	get_builtins(t_cmd *cmd)
{
	int	index;

	index = 0;
	while (cmd->data->builtins[index].name
		&& ft_strncmp(cmd->data->builtins[index].name,
			cmd->node->right->value[0], ft_strlen(cmd->node->right->value[0]))
		&& ft_strncmp(cmd->data->builtins[index].name + 1,
			cmd->node->right->value[0],
			ft_strlen(cmd->node->right->value[0])))
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
void	exec_builtin(t_cmd *cmd, t_builtins builtin)
{
	char	*cmd_path;

	cmd_path = NULL;
	cmd_path = join_cmd(cmd->node->right->value, cmd_path);
	if (!cmd_path)
		exit(127);
	builtin.builtin(cmd_path);
	free(cmd_path);
	exit(cmd->data->status);
}
