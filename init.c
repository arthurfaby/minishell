#include "minishell.h"

int	init_data(t_data *data, char **envp)
{
	data->path = ft_split(path_finder(envp), ':');
	//data->cmd = malloc(sizeof(t_elem));
	//if (!data->cmd)
	//	return (-1);
	//data->cmd->head = NULL;
	//data->cmd->size = 0;
	data->envp = envp;
	data->env = NULL;
	parse_env(data, envp);
	return (1);
}
