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

enum e_types {
	PIPE,
	COMMAND,
	ARGS,
	REDIRECTION
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

typedef struct s_var
{
	char			*name;
	char			*value;
	struct s_var	*next;
}			t_var;

typedef struct s_data
{
	char	**path;
	char	**envp;
	t_var	*env;
}				t_data;

typedef struct s_cmd
{
	int		infile;
	int		outfile;
	int		*pipe[2];
	pid_t	*pids;
	int		id;
	t_data	*data;
	t_node	*node;
}			t_cmd

// minishell.c
char	*path_finder(char **envp);

// prompt.c
void	free_node(t_node *node);
void	free_ast(t_ast *ast);
void	display_prompt(t_data *data);

// parser.c
char	*parser(char *line);

// parser_utils.c
int		skip_whitespace(char *cmd, int index_start);
char	*spaces_redirections(char *cmd);
int		get_size_cmd(char *line);

// signal.c
void	sig_handler(int sigcode);
int		init_sig(void);

// tokenizer.c
t_ast	*tokenizer(char *cmd, t_ast *ast);

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

// tree.c
t_node	*new_node(int type, char **content);
void	add_left(t_node *node, t_node *new);
void	add_right(t_node *node, t_node *new);

// tokenizer.c
t_ast	*tokenizer(char *cmd, t_ast *ast);

// tokenizer_utils.c
char	**get_split_args(char **split, char **args);
char	**get_split_redirect(char **split, char **redirect);
void	split_args_redirect(t_ast *ast);
char	**get_content(char *str);

// ft_unset.c
void	ft_unset(t_data *data, char *line);

// ft_pwd.c
void	ft_pwd(void);

// ft_export.c
void	ft_export(t_data *data, char *line);

// ft_echo.c
void	ft_echo(char *option, char **args);

// ft_cd.c
void	ft_cd(char *path);

// ft_exec.c
void	ft_exec(t_ast *ast);

#endif
