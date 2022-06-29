#include "minishell.h"

/*
* -------------------------
* Function: parse_env 
* ------------------------- 
*
*	create and malloc the env
*
* Params:
*	t_data	*data 	: minishell datas
*	char	**envp	: the env of the user
*
* Returns:
*	int (-1)		: malloc error
*	int	(1)			: everyting is ok
*
* -------------------------
*/
int	parse_env(t_data *data, char **envp)
{
	int		i;
	char	**new_env;

	i = 0;
	while (envp[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (-1);
	i = 0;
	while (envp[i])
	{
		new_env[i] = ft_strdup(envp[i]);
		i++;
	}
	new_env[i] = NULL;
	data->env = new_env;
	return (1);
}

/*
* -------------------------
* Function: ft_env
* ------------------------- 
*
*	print the env on the shell
*
* Params:
*	t_data	*data : minishell datas
*
* -------------------------
*/
void	ft_env(t_data *data, char *cmd)
{
	int	i;

	(void)cmd;
	i = 0;
	while (data->env[i])
	{
		ft_printf("%s\n", data->env[i]);
		i++;
	}
}
