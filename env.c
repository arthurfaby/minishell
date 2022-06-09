#include "minishell.h"

int	parse_env(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!data->env)
			data->env = new_var(envp[i]);
		else
			var_add_last(&data->env, new_var(envp[i]));
		i++;
	}
	return (1);
}

int	ft_env(t_data *data)
{
	t_var	*tmp;

	tmp = data->env;	
	while (tmp)
	{
		printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
	return (1);
}
