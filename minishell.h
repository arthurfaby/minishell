/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:10:15 by vnaud             #+#    #+#             */
/*   Updated: 2022/06/01 11:33:53 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

enum e_commands {
	ECHO = "echo",
	CD = "cd",
	PWD = "pwd",
	EXPORT = "export",
	UNSET = "unset",
	ENV = "env",
	EXIT = "exit"
};

enum e_redirections {
	I_REDIR = "<",
	O_REDIR = ">",
	O_REDIR_APPEND = ">>",
	I_DELIM = "<<",
	PIPE = "|"
};

enum e_metachar {
	DOLLAR = "$",
	QUEST_MARK = "?",
	QUOTE = "\'",
	D_QUOTE = "\""
}

enum e_types {
	COMMAND,
	/* SEPARATOR, */
	REDIRECTION,
	METACHAR,
	VALUE
};

typedef struct s_elem
{
	int				type;
	int				id;
	char			*value;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef struct s_cmd
{
	int		size;
	t_elem	*head;
}			t_cmd;

typedef struct s_data
{
	char	**path;
	t_cmd	*cmd;
}				t_data;

// minishell.c
char	*path_finder(char **envp);

// prompt.c
void	display_prompt(t_data *data);

// history.c
t_elem	*new_elem(char *elem);
void	add_elem_cmd(t_data *data, char *elem);
void	free_cmd(t_data *data);

#endif
