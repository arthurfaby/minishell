/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:03:56 by afaby             #+#    #+#             */
/*   Updated: 2022/07/04 11:03:57 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: check_line_export
* ------------------------- 
*
*	check line to export
*
* Params:
*	char	*line	: line to export
*
* Returns:
*	int	(0)			: not ok
8	int	(1)			: ok 
*
* -------------------------
*/
int	check_line_export(char *line)
{
	int	i;

	i = 0;
	if (!isalpha(line[i]))
		return (0);
	while (line[i] && isalnum(line[i]))
		i++;
	if (line[i] != '=')
		return (0);
	return (1);
}

/*
* -------------------------
* Function: ft_export
* ------------------------- 
*
* Create/Modify env variable
*
* Params:
*	char *line		: user input line
*
* -------------------------
*/
void	ft_export(char *line)
{
	char	**args;
	int		i;

	args = ft_split(line, ' ');
	if (!args || !*args)
		return ;
	i = 1;
	while (args[i])
	{
		if (check_line_export(args[i]))
			add_env(args[i]);
		i++;
	}
	g_data->status = 0;
	ft_sstrdel(args);
}
