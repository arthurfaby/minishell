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
