/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:02:44 by afaby             #+#    #+#             */
/*   Updated: 2022/07/04 11:02:45 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: comp_var_name 
* ------------------------- 
*
*	compare names of two variables
*
* Params:
*	char	*s1			: first variable
*	char	*s2			: second variable
*
* Returns:
*	int (1)	or ('=')	: names are equal
*	int (*s1 - *s2)		: names are not equal
*
* -------------------------
*/
int	comp_var_name(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] && s1[i] != '=')
		i++;
	j = 0;
	while (s1[j] && s2[j] && j < i)
	{
		if (s1[j] != s2[j])
			return (1);
		j++;
	}
	return (s1[j] - s2[j] - '=');
}

/*
* -------------------------
* Function: check_env_dup
* ------------------------- 
*
*	check if variable to export already exists
*
* Params:
*	char	*str	: varible to export
*
* Returns:
*	int (0)			: the variable does not already exists
*	int (1)			: the variable already exists
*
* -------------------------
*/
int	check_env_dup(char *str)
{
	int		i;

	i = 0;
	while (g_data->env[i])
	{
		if (comp_var_name(g_data->env[i], str) == -61)
			break ;
		i++;
	}
	if (!g_data->env[i])
		return (0);
	free(g_data->env[i]);
	g_data->env[i] = NULL;
	g_data->env[i] = ft_strdup(str);
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
*	char	*name	: name of the variable
*
* Returns:
*	char *			: value of the variable
*	NULL			: if name is NULL or if variable does not exists
*
* -------------------------
*/
char	*get_env_value(char *name)
{
	int	i;
	int	len;

	if (!name)
		return (NULL);
	if (!*name)
		return ("$");
	len = ft_strlen(name);
	i = 0;
	while (g_data->env[i])
	{
		if (ft_strcmp(g_data->env[i], name) == '=')
			return (g_data->env[i] + len + 1);
		i++;
	}
	return (NULL);
}
