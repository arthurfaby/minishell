#include "minishell.h"

static t_var	*new_var_name_value(char *name, char *value)
{
	t_var	*new;

	new = malloc(sizeof(t_var));
	if (!new)
		return (NULL);
	new->name = name;
	new->value = value;
	return (new);
}

int	add_env(char *str, t_data *data)
{
	int		size;
	t_var	*tmp;
	t_var	**env;
	int		i;
	
	size = 0;
	while (data->env[size])
		size++;
	env = malloc((size + 1) * sizeof(t_var) + sizeof(void *));
	if (!env)
		return (-1);
	i = 0;
	while (data->env[i])
	{
		tmp = new_var_name_value(data->env[i]->name, data->env[i]->value);
		if (!tmp)
			return (-1); // FREE EVERYTHING
		env[i] = tmp;
		i++;
	}
	env[i++] = new_var(str);
	env[i] = NULL;
	free_env(data);
	data->env = env;
	return (1);
}
