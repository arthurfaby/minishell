/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:10:15 by vnaud             #+#    #+#             */
/*   Updated: 2022/06/01 09:25:22 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

typedef struct	s_cmd
{
	int	id;
	char			*cmd;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

typedef struct	s_history
{
	int		size;
	t_cmd	*head;
	int		max;
}			t_history;

typedef struct	s_data
{
	char		**path;
	t_history	*history;
}				t_data;

// minishell.c
char	*path_finder(char **envp);

// prompt.c
void	display_prompt(t_data *data);

// history.c
t_cmd	*new_cmd(char *cmd);
void	add_cmd_history(t_data *data, char *cmd);
void	del_last_history(t_data *data);
void	free_history(t_data *data);

#endif
