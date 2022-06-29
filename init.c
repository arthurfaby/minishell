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
void	init_builtins(t_data *data)
{
	data->builtins[0].name = " echo ";
	data->builtins[0].builtin = ft_echo;
	data->builtins[1].name = " cd ";
	data->builtins[1].builtin = ft_cd;
	data->builtins[2].name = " pwd ";
	data->builtins[2].builtin = ft_pwd;
	data->builtins[3].name = " export ";
	data->builtins[3].builtin = ft_export;
	data->builtins[4].name = " unset ";
	data->builtins[4].builtin = ft_unset;
	data->builtins[5].name = " env ";
	data->builtins[5].builtin = ft_env;
	data->builtins[6].name = NULL;
}

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
	data->builtins = malloc(sizeof(t_builtins) * 7);
	if (!data->builtins)
		return (0);
	init_builtins(data);
	return (1);
}
