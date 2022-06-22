#include "minishell.h"

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
	new_env = (char **)ft_calloc(sizeof(char *), i + 1);
	if (!new_env)
		return ;
	i = 0;
	while (data->env[i])
	{
		if (comp_var_name(data->env[i], name) != 0)
			new_env[i - found] = ft_strdup(data->env[i]);
		else
			found = 1;
		i++;
	}
	new_env[i - found] = NULL;
	free_env(data);
	data->env = new_env;
}

void	modif_env(t_data *data, char *name, char *nvalue)
{
	int		len;
	int		i;
	char	*tmp;

	i = 0;
	len = ft_strlen(name);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], name, len) == 0)
		{
			free(data->env[i]);
			tmp = ft_strjoin("=", nvalue);
			data->env[i] = ft_strjoin(name, tmp);
			free(tmp);
			tmp = NULL;
			return ; 
		}
		i++;
	}
}
