/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:04:15 by afaby             #+#    #+#             */
/*   Updated: 2022/07/04 11:04:16 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: ft_unset
* ------------------------- 
*
*	unset env variable
*
* Params:
* 	char *line		: user input line
*
* -------------------------
*/
void	ft_unset(char *line)
{
	char	**args;
	int		i;
	int		new_status;

	new_status = 0;
	args = ft_split(line, ' ');
	if (!args || !*args)
		return ;
	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
		{
			ft_putstr_fd("minishell: unset: '", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			new_status = 1;
		}
		else
			remove_env(args[i]);
		i++;
	}
	g_data->status = new_status;
	ft_sstrdel(args);
}
