#include "minishell.h"

t_var	*new_var(char *str)
{
	t_var	*new;
	char	*name;
	char	*value;
	int		i;
	int		j;

	i = 0;
	new = malloc(sizeof(t_var));
	if (!new)
		return (NULL);
	while (str[i] != '=')
		i++;
	name = malloc(i + 1);
	if (!name)
		return (free(new), NULL);
	i = -1;
	while (str[++i] != '=')
		name[i] = str[i];
	j = i + 1;
	while (str[j])
		j++;
	value = malloc(j - i);
	if (!value)
		return (free(new), free(name), NULL);
	j = i;
	while (str[++j])
		value[j - i - 1] = str[j];
	new->name = name;
	new->value = value;
	return (new);
}

int	count_var(char **envp)
{
	int	size;

	size = 0;
	while (envp[size])
		size++;
	return (size);
}

int	parse_env(t_data *data, char **envp)
{
	int	size;
	int	i;

	size = count_var(envp);
	data->env = malloc(size * sizeof(t_var) + sizeof(void *));
	if (!data->env)
		return (-1);
	i = 0;
	while (envp[i])
	{
		data->env[i] = new_var(envp[i]);
		if (!data->env[i])
			return (-1); // FREE THE BEGGINING
		i++;
	}
	data->env[i] = NULL;
	return (1);
}

int	ft_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		printf("%s=%s\n", data->env[i]->name, data->env[i]->value);
		i++;
	}
	return (1);
}
