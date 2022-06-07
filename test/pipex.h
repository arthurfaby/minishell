/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:50:00 by vnaud             #+#    #+#             */
/*   Updated: 2022/05/08 14:41:39 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "libft/includes/libft.h"

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		child_pid[2];
	int		pp[2];
	char	**cmdpth;
	char	*envpth;
	char	*cmd;
	char	**args_child;
}			t_data;

void	ft_err_msg(char *msg);
char	*path_finder(char **envp);
void	free_data(t_data *data);
void	first_child(t_data *data, char **argv, char **envp);
void	second_child(t_data *data, char **argv, char **envp);
void	close_pipe(t_data *data);
char	*get_cmd(t_data *data, char **envp);
void	free_child(t_data *data, int id);

#endif
