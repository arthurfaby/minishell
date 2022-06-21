#include "minishell.h"

/*
* -------------------------
* Function: comp_var_name 
* ------------------------- 
*
*	compare names of two variables
*
* Params:
*	char	*s1		: first variable
*	char	*s2		: second variable
*
* Returns:
*	int (1)			: names are equal
*	int (number)	: names are not equal
*
* -------------------------
*/
int	comp_var_name(char *s1, char *s2)
{
	while (*s1 && *s1 != '=' && *s2 && *s2 != '=')
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*
* -------------------------
* Function: check_env_dup
* ------------------------- 
*
*	check if variable to export already exists
*
* Params:
*	t_data	*data	: minishell datas
*	char	*str	: varible to export
*
* Returns:
*	int (0)			: the variable does not already exists
*	int (1)			: the variable already exists
*
* -------------------------
*/
int	check_env_dup(t_data *data, char *str)
{
	int		i;

	i = 0;
	while (data->env[i])
	{
		if (!comp_var_name(data->env[i], str))
			break ;
		i++;
	}
	if (!data->env[i])
		return (0);
	free(data->env[i]);
	data->env[i] = ft_strdup(str);
	return (1);
}

/*
* -------------------------
* Function: add_env
* ------------------------- 
*
*	add variable to the env
*
* Params:
*	t_data	*data	: minishell datas
*	char	*str	: variable to export
*
* Returns:
*	int	(0)			: everything is ok
*	int	(-1)		: malloc error
*
* -------------------------
*/
int	add_env(t_data *data, char *str)
{
	char	**new_env;
	int		i;

	i = 0;
	if (check_env_dup(data, str))
		return (0);
	while (data->env[i])
		i++;
	new_env = (char **)ft_calloc(sizeof(char *), (i + 2));
	if (!new_env)
		return (-1);
	i = 0;
	while (data->env[i])
	{
		new_env[i] = ft_strdup(data->env[i]);
		i++;
	}
	new_env[i++] = ft_strdup(str);
	new_env[i] = NULL;
	free_env(data);
	data->env = new_env;
	return (0);
}

/*
* -------------------------
* Function: get_env_value
* ------------------------- 
*
*	return value of a variable based on its name
*
* Params:
*	t_data	*data	: minishell datas
*	char	*name	: name of the variable
*
* Returns:
*	char *			: value of the variable
*	NULL			: if name is NULL or is variable does not exists
*
* -------------------------
*/
char	*get_env_value(t_data *data, char *name)
{
	int	i;
	int	len;

	if (!name)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], name, len) == 0)
			return (data->env[i] + len + 1);
		i++;
	}
	return (NULL);
}

/*
* -------------------------
* Function: remove_env
* ------------------------- 
*
*	Remove the name envp variable from list
*
* Params:
*	char *name		: envp name to remove
*	t_data *data	: data struct
*
* -------------------------
*/
void	remove_env(t_data *data, char *name)
{
	char	**new_env;
	int		i;
	int		found;

	found = 0;
	i = 0;
	while (data->env[i])
		i++;
	new_env = (char **)ft_calloc(sizeof(char *), i);
	if (!new_env)
		return ;
	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], name, ft_strlen(name)) != 0)
			new_env[i - found] = ft_strdup(data->env[i]);
		else
			found = 1;
		i++;
	}
	new_env[i] = NULL;
	free_env(data);
	data->env = new_env;
}
