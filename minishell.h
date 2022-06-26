#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <dirent.h>
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

typedef struct s_data	t_data;

typedef struct s_cmd
{
	int		infile;
	int		outfile;
	int		**pipe;
	pid_t	*pids;
	int		id;
	t_data	*data;
	t_node	*node;
	int		nb_cmd;
}			t_cmd;

typedef struct s_data
{
	char	**path;
	char	**envp;
	char	**commands;
	char	**redirections;
	char	**metachars;
	char	**env;
	int		status;
	t_cmd	*cmd;
}				t_data;

// minishell.c
char	*path_finder(char **envp);

// prompt.c
void	free_node(t_node *node);
void	free_ast(t_ast *ast);
void	display_prompt(t_data *data);

// parser.c
char	*parser(t_data *data, char *line);

// parser_utils.c
int		skip_whitespace(char *cmd, int index_start);
char	*spaces_redirections(char *cmd);
int		get_size_cmd(t_data *data, char *line);

// signal.c
void	sig_handler(int sigcode);
void	message_signal(int status);
void	create_handler(void);
void	delete_handler(void);
void	ignore_handler(void);

// tokenizer.c
t_ast	*tokenizer(char *cmd, t_ast *ast);

// init.c
int		init_data(t_data *data, char **envp);

// env.c
int		parse_env(t_data *data, char **envp);
void	ft_env(t_data *data);

// env_utils.c
int		check_env_dup(t_data *data, char *str);
char	*get_env_value(t_data *data, char *name);
int		comp_var_name(char *s1, char *s2);

// env_modif.c
int		add_env(t_data *data, char *str);
void	remove_env(t_data *data, char *name);

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

// ft_export.c
void	ft_export(t_data *data, char *line);

// ft_echo.c
void	ft_echo(t_data *data, char *cmd);

// ft_exec.c
char	*get_cmd(t_cmd *cmd);
int		get_number_pipe(t_ast *ast);
t_cmd	*init_cmd(t_data *data);
int		get_redirect(t_cmd *cmd);
void	simple_child(t_cmd *cmd);
void	open_pipe(t_cmd *cmd);
void	close_pipe(t_cmd *cmd, int id);
void	exec_multiple_cmd(t_ast *ast, t_cmd *cmd);
void	ft_exec(t_data *data, t_ast *ast);

// ft_exec_utils.c
void	first_child(t_cmd *cmd);
void	mid_child(t_cmd *cmd);
void	last_child(t_cmd *cmd);

// ft_cd.c
void	ft_cd(t_data *data, char *path);

// ft_pwd.c
void	ft_pwd(t_data *data);

// ft_exit.c
void	ft_exit(t_data *data, char *line, char *cmd, t_ast *ast);

#endif
