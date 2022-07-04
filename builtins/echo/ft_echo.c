/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:02:12 by afaby             #+#    #+#             */
/*   Updated: 2022/07/04 12:13:14 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: ft_echo 
* ------------------------- 
*
*	echo builtin
*
* Params:
*	char	*cmd	: parsed user input line
*
* -------------------------
*/
void	ft_echo(char *cmd)
{
	int	option;

	option = 0;
	while (*cmd && ft_iswhitespace(*cmd))
		cmd++;
	cmd += 4;
	if (ft_iswhitespace(*cmd))
		cmd++;
	while (ft_strncmp(cmd, "-n", 2) == 0 && (cmd[2] == ' ' || !cmd[2]))
	{
		if (cmd[2] == ' ')
			cmd += 3;
		else
			cmd += 2;
		option = 1;
	}
	ft_putstr(cmd);
	if (!option)
		ft_putchar('\n');
	g_data->status = 0;
}
