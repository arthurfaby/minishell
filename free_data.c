#include "minishell.h"

void	free_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		free(data->env[i]);
		data->env[i] = NULL;
		i++;
	}
	free(data->env);
}

void	free_data(t_data *data)
{
	free_env(data);
	free(data->cmd);
	ft_sstrdel(data->commands);
	ft_sstrdel(data->redirections);
	ft_sstrdel(data->metachars);
	ft_sstrdel(data->path);
}
