/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:02:00 by afaby             #+#    #+#             */
/*   Updated: 2022/07/04 11:02:01 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: init_builtins 
* ------------------------- 
*
*	init builtins structure
*
* -------------------------
*/
void	init_builtins(void)
{
	g_data->builtins[0].name = " echo ";
	g_data->builtins[0].builtin = ft_echo;
	g_data->builtins[1].name = " cd ";
	g_data->builtins[1].builtin = ft_cd;
	g_data->builtins[2].name = " pwd ";
	g_data->builtins[2].builtin = ft_pwd;
	g_data->builtins[3].name = " export ";
	g_data->builtins[3].builtin = ft_export;
	g_data->builtins[4].name = " unset ";
	g_data->builtins[4].builtin = ft_unset;
	g_data->builtins[5].name = " env ";
	g_data->builtins[5].builtin = ft_env;
	g_data->builtins[6].name = NULL;
}

/*
* -------------------------
* Function: init_data
* ------------------------- 
*
*	initialize data struct
*
* Params:
*	char **envp		: env variable from start
*
* Returns:
*	int (0)	: malloc error
*	int (1)	: everything is ok
*
* -------------------------
*/
int	init_data(char **envp)
{
	g_data = malloc(sizeof(t_data));
	if (!g_data)
		return (0);
	g_data->env = NULL;
	parse_env(envp);
	g_data->status = 0;
	g_data->builtins = malloc(sizeof(t_builtins) * 7);
	if (!g_data->builtins)
		return (0);
	init_builtins();
	return (1);
}
