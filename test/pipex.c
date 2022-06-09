/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:49:22 by vnaud             #+#    #+#             */
/*   Updated: 2022/06/07 16:37:15 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



void	first_child(t_data *data, char **argv, char **envp)
{
	data->infile = open(argv[1], O_RDONLY);
	data->outfile = open(argv[2], O_RDONLY);
	dup2(data->infile, 0);
	dup2(data->outfile, 0);
	execve(data->cmd, data->args_child, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		status;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		ft_err_msg(strerror(errno));
	if (pipe(data->pp) < 0)
		ft_err_msg(strerror(errno));
	data->child_pid[0] = fork();
	if (data->child_pid[0] < 0)
		ft_err_msg(strerror(errno));
	if (data->child_pid[0] == 0)
		first_child(data, argv, envp);
	close_pipe(data);
	waitpid(data->child_pid[0], &status, 0);
	free(data);
	return (status);
}
