#include "minishell.h"

/*
* -------------------------
* Function: init_data
* ------------------------- 
*
*	initialize data struct
*
* Params:
*	t_data *data	: data struct of minishell program
*	char **envp		: env variable from start
*
* Returns:
*	int (0)	: Problem
*	int (1)	: No problem
*
* -------------------------
*/
int	init_data(t_data *data, char **envp)
{
	data->env = NULL;
	parse_env(data, envp);
	data->path = ft_split(get_env_value(data, "PATH"), ':');
	data->status = 0;
	return (1);
}
