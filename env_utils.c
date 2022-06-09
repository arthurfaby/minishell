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
	name = malloc(sizeof(char) * (i + 1));
	if (!name)
		return (free(new), NULL);
	i = -1;
	while (str[++i] != '=')
		name[i] = str[i];
	name[i] = '\0';
	j = i + 1;
	while (str[j])
		j++;
	value = malloc(sizeof(char) * (j - i));
	if (!value)
		return (free(new), free(name), NULL);
	j = i;
	while (str[++j])
		value[j - i - 1] = str[j];
	str[j] = '\0';
	new->name = name;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	var_add_last(t_var **lst, t_var *new)
{
	t_var	*tmp;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int	check_dup(t_var **lst, t_var *new)
{
	t_var	*tmp;
	char	*old;

	if (!lst)
		return (0);
	tmp = *lst;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, new->name) == 0)
		{
			old = tmp->value;
			tmp->value = new->value;
			free(old);
			free(new->name);
			free(new);
			return (1);
		}
		tmp = tmp->next;
	}
	free(new->name);
	free(new->value);
	free(new);
	return (0);
}

int	add_env(char *str, t_data *data)
{
	if (!check_dup(&data->env, new_var(str)))
		var_add_last(&data->env, new_var(str));
	return (1);
}

void	remove_env(char *name, t_data *data)
{
	t_var	*tmp;
	t_var	*old;	
	
	if (!data->env)
		return ;
	tmp = data->env;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->next->name, name) == 0)
		{
			old = tmp->next;
			tmp->next = tmp->next->next;
			free(old->name);
			free(old->value);
			free(old);
			return ;
		}
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->name, name) == 0)
	{
		free(tmp->name);
		free(tmp->value);
		free(tmp);
		tmp = NULL;
	}
}
