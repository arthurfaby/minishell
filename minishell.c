/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:38:54 by afaby             #+#    #+#             */
/*   Updated: 2022/06/02 10:10:56 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*path_finder(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1)
		ft_usage_err(argv[0], "");
	data.commands = ft_split(COMMANDS, ' ');
	data.redirections = ft_split(REDIRECTIONS, ' ');
	data.metachars = ft_split(METACHARS, ' ');
	data.path = ft_split(path_finder(envp), ':');
	data.cmd = malloc(sizeof(t_elem));
	if (!data.cmd)
		return (1);
	data.cmd->head = NULL;
	data.cmd->size = 0;
	data.envp = envp;
	init_sig();
	display_prompt(&data);
	free(data.cmd);
	ft_sstrdel(data.commands);
	ft_sstrdel(data.redirections);
	ft_sstrdel(data.metachars);
	ft_sstrdel(data.path);
	return (0);
}
