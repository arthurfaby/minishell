#include "minishell.h"

void	free_env(t_data *data)
{
	t_var	*tmp;
	t_var	*old;

	tmp = data->env;
	while (tmp)	
	{
		old = tmp;
		tmp = tmp->next;
		free(old->name);
		free(old->value);
		free(old);
	}
}

void	free_data(t_data *data)
{
	free_env(data);
	free(data->cmd);
	ft_sstrdel(data->path);
}
