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

# define PROMPT "\e[48;5;25m\e[38;5;226m minishell ➔ \e[0m "

# define COMMANDS "echo cd pwd export unset env exit"
# define REDIRECTIONS "< > << >> |"
# define METACHARS "$ ? \' \""

enum e_types {
	COMMAND,
	REDIRECTION,
	METACHAR,
	VALUE
	/* SEPARATOR, */
	/*
	PIPE
	COMMAND
	ARGS
	REDIRECTION
	*/
};

typedef struct s_node
{
	int				type;
	char			**value;
	struct s_node	*parent;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

typedef struct s_ast
{
	t_node	*root;
}			t_ast;

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
char	*parser(t_data *data, char *line);

// parser_utils.c
int		skip_whitespace(char *cmd, int index_start);
int		isinsstr(char **sstr, char *word);
char	*get_str(char **sstr, char *word);

// exec.c
char	*get_cmd(t_data *data);
void	exec_cmd(t_data *data);

// signal.c
int		init_sig(void);

// tokenizer.c
int	tokenizer(char *cmd);

#endif
