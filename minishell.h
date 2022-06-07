#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

# define CMD_NOT_FOUND "minishell: command not found\n"
# define PROMPT "\e[48;5;25m\e[38;5;226m minishell ➔ \e[0m "

# define COMMANDS "echo cd pwd export unset env exit"
# define REDIRECTIONS "< > << >> |"
# define METACHARS "$ ? \' \" ="

enum e_commands {
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
};

enum e_redirections {
	I_REDIR,
	O_REDIR,
	O_REDIR_APPEND,
	I_DELIM,
	PIPE
};

enum e_metachar {
	DOLLAR,
	QUEST_MARK,
	QUOTE,
	D_QUOTE
};

enum e_types {
	COMMAND,
	REDIRECTION,
	METACHAR,
	VALUE
	/* SEPARATOR, */
};

typedef struct s_var
{
	char			*name;
	char			*value;
	struct s_var	*next;
}			t_var;

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
	char	**envp;
	char	**commands;
	char	**redirections;
	char	**metachars;
	t_var	*env;
	t_cmd	*cmd;
}				t_data;

// minishell.c
char	*path_finder(char **envp);

// prompt.c
void	print_cmd_stack(t_data *data);
void	free_cmd_stack(t_data *data);
void	display_prompt(t_data *data);

// history.c
t_elem	*new_elem(char *elem, int type);
void	add_elem_cmd(t_data *data, t_elem *new);
void	free_cmd(t_data *data);

// parser.c
int		skip_whitespace(char *cmd, int index_start);
int		isinsstr(char **sstr, char *word);
char	*get_str(char **sstr, char *word);
int		parser(t_data *data, char *cmd);

// exec.c
char	*get_cmd(t_data *data);
void	exec_cmd(t_data *data);

// signal.c
int		init_sig(void);

// init.c
int		init_data(t_data *data, char **envp);

// env.c
int		parse_env(t_data *data, char **envp);
int		ft_env(t_data *data);

// env_utils.c
t_var	*new_var(char *str);
void	var_add_last(t_var **lst, t_var *new);
int		check_dup(t_var **lst, t_var *new);
int		add_env(char *str, t_data *data);
void	remove_env(char *name, t_data *data);

// free_data.c
void	free_env(t_data *data);
void	free_data(t_data *data);

#endif
