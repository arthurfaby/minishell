/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:02:38 by afaby             #+#    #+#             */
/*   Updated: 2022/07/04 11:02:39 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: add_env
* ------------------------- 
*
*	add variable to the env
*
* Params:
*	char	*str	: variable to export
*
* Returns:
*	int	(0)			: everything is ok
*	int	(-1)		: malloc error
*
* -------------------------
*/
int	add_env(char *str)
{
	char	**new_env;
	int		i;

	i = 0;
	if (check_env_dup(str))
		return (0);
	while (g_data->env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (-1);
	i = 0;
	while (g_data->env[i])
	{
		new_env[i] = ft_strdup(g_data->env[i]);
		i++;
	}
	new_env[i++] = ft_strdup(str);
	new_env[i] = NULL;
	ft_sstrdel(g_data->env);
	g_data->env = new_env;
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
*
* -------------------------
*/
void	remove_env(char *name)
{
	char	**new_env;
	int		i;
	int		found;

	found = 0;
	i = 0;
	while (g_data->env[i])
		i++;
	new_env = (char **)ft_calloc(sizeof(char *), i + 1);
	if (!new_env)
		return ;
	i = 0;
	while (g_data->env[i])
	{
		if (comp_var_name(g_data->env[i], name) != 0)
			new_env[i - found] = ft_strdup(g_data->env[i]);
		else
			found = 1;
		i++;
	}
	new_env[i - found] = NULL;
	ft_sstrdel(g_data->env);
	g_data->env = new_env;
}

/*
* -------------------------
* Function: modif_env 
* ------------------------- 
*
*	modify a the value of a var in env
*
* Params:
*	char	*name	: name of var
*	char	*nvalue	: new value
*
* -------------------------
*/
void	modif_env(char *name, char *nvalue)
{
	int		len;
	int		i;
	char	*tmp;

	i = 0;
	len = ft_strlen(name);
	while (g_data->env[i])
	{
		if (ft_strncmp(g_data->env[i], name, len) == 0)
		{
			free(g_data->env[i]);
			tmp = ft_strjoin("=", nvalue);
			g_data->env[i] = ft_strjoin(name, tmp);
			free(tmp);
			tmp = NULL;
			return ;
		}
		i++;
	}
}
