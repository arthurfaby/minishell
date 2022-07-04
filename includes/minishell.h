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

typedef struct s_builtins
{
	char	*name;
	void	(*builtin)(char *cmd);
}			t_builtins;

typedef struct s_data
{
	char		**env;
	int			status;
	t_cmd		*cmd;
	t_builtins	*builtins;
}				t_data;

t_data					*g_data;

// ----------------- MAIN ----------------
// minishell.c
char		*path_finder(char **envp);

// ----------------- PROMPT ----------------
// prompt.c
void		free_node(t_node *node);
void		free_ast(t_ast *ast);
void		display_prompt(void);

// ----------------- PARSER ----------------
// parser.c
char		*parser(char *line);

// parser_size.c
int			get_size_cmd(char *line);

// parser_size_utils.c
void		get_size_error_code(int *index, int *size);
void		get_size_dollar(char *line, int *index, int *size);
void		get_size_simple_quotes(char *line, int *index, int *size);
void		get_size_double_quotes(char *line, int *index, int *size);
void		get_size_white_spaces(char *line, int *index, int *size);

// parser_treat.c
void		treat_error_code(char *res, int *index, int *index_res);
void		treat_dollar(char *res, char *line, int *index, int *index_res);
void		treat_simple_quotes(char *res, char *line, int *index, int *index_res);
void		treat_double_quotes(char *res, char *line, int *index, int *index_res);
void		treat_white_spaces(char *res, char *line, int *index, int *index_res);

// parser_utils.c
int			skip_whitespace(char *cmd, int index_start);
void		get_size_spaces_redirections(char *cmd, int *size);
void		remove_spaces_redirections(char *res, char *cmd,
			int *index, int *index_res);
char		*spaces_redirections(char *cmd);
int			ft_intlen(int n);

// ----------------- SIGNAL ----------------
// signal.c
void		convert_signal(void);
void		message_signal(int status);

// handler.c
void		sig_handler(int sigcode);
void		create_handler(void);
void		delete_handler(void);
void		ignore_handler(void);

// ----------------- ALLOCS ----------------
// init.c
int			init_data(char **envp);

// free_data.c
void		free_all(char *line, char *cmd, t_ast *ast);
void		free_env(void);
void		free_data(void);

// ----------------- TOKENIZER ----------------
// tokenizer.c
int			fill_ast(t_ast *ast, int size);
void		fill_nodes(t_node *it);
t_ast		*tokenizer(char *cmd, t_ast *ast);

// set.c
t_ast		*set_unique_cmd(t_ast *ast, char **pipe);
void		set_multi_cmd(t_ast *ast, char **pipe);
void		split_args_redirect(t_ast *ast);

// get.c
char		**get_split_args(char **split, char **args);
char		**get_split_redirect(char **split, char **redirect);
char		**get_content(char *str);

// free.c
void		free_trio(char **split, char **args, char **redirect);
char		**free_before(void **args, int size);

// tree.c
t_node		*new_node(int type, char **content);
void		add_left(t_node *node, t_node *new);
void		add_right(t_node *node, t_node *new);

// ----------------- BUILTINS ----------------
// -------- ENV -------
// env.c
int			parse_env(char **envp);
void		ft_env(char *cmd);

// env_utils.c
int			check_env_dup(char *str);
char		*get_env_value(char *name);
int			comp_var_name(char *s1, char *s2);

// env_modif.c
int			add_env(char *str);
void		remove_env(char *name);

// -------- UNSET -------
// ft_unset.c
void		ft_unset(char *line);

// -------- EXPORT -------
// ft_export.c
void		ft_export(char *line);

// -------- ECHO -------
// ft_echo.c
void		ft_echo(char *cmd);

// -------- CD -------
// ft_cd.c
void		ft_cd(char *path);

// -------- PWD -------
// ft_pwd.c
void		ft_pwd(char *cmd);

// -------- EXIT -------
// ft_exit.c
void		ft_exit(char *line, char *cmd, t_ast *ast);

// ----------------- EXEC ----------------
// child.c
void		first_child(t_cmd *cmd);
void		mid_child(t_cmd *cmd);
void		last_child(t_cmd *cmd);
void		start_child(t_cmd *cmd, t_node *it);
void		simple_child(t_cmd *cmd);

// pipe.c
void		open_pipe(t_cmd *cmd);
void		close_pipe(t_cmd *cmd, int id);
void		close_pipe(t_cmd *cmd, int id);
void		free_pipe(t_cmd *cmd);
int			get_number_pipe(t_ast *ast);

// redirection.c
int			get_input_redirect(t_cmd *cmd, int index);
int			get_output_redirect(t_cmd *cmd, int index);
int			get_redirect(t_cmd *cmd);
void		redirect_check(t_cmd *cmd);
int			fill_docfile(char *eof);

// command.c
char		*get_cmd(t_cmd *cmd);
t_cmd		*init_cmd(void);
char		*join_cmd(char **value, char *cmd);
void		get_nb_cmd(t_ast *ast, t_cmd *cmd);
void		command_not_found(t_cmd *cmd);

// builtins.c
t_builtins	get_builtins(t_cmd *cmd);
void		exec_builtin(t_cmd *cmd, t_builtins builtin);

// ft_exec.c
void		exec_simple_command(t_cmd *cmd, t_node *it);
void		exec_multiple_cmd(t_ast *ast, t_cmd *cmd);
void		ft_exec(t_ast *ast);

#endif
