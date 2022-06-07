#include "minishell.h"

int	init_data(t_data *data, char **envp)
{
	data->commands = ft_split(COMMANDS, ' ');
	data->redirections = ft_split(REDIRECTIONS, ' ');
	data->metachars = ft_split(METACHARS, ' ');
	data->path = ft_split(path_finder(envp), ':');
	data->cmd = malloc(sizeof(t_elem));
	if (!data->cmd)
		return (-1);
	data->cmd->head = NULL;
	data->cmd->size = 0;
	data->envp = envp;
	parse_env(data, envp);
	return (1);
}
