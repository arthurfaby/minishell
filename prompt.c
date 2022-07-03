#include "minishell.h"

/*
* -------------------------
* Function: display_prompt
* ------------------------- 
*
*	display minishell prompt
*
* Params:
*	t_data *data	: data from the minishell
*
* -------------------------
*/
void	display_prompt(t_data *data)
{
	char	*line;
	char	*cmd;
	t_ast	*ast;

	line = readline(PROMPT);
	cmd = NULL;
	ast = NULL;
	while (line)
	{
		if (*line)
		{
			add_history(line);
			cmd = parser(data, line);
			ast = tokenizer(cmd, ast);
			if (!ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, " exit")
				|| !ft_strncmp(cmd, " exit ", 6) || !ft_strncmp(cmd, "exit ", 5))
				ft_exit(data, line, cmd, ast);
			else if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, " echo")
				|| !ft_strncmp(cmd, " echo ", 6) || !ft_strncmp(cmd, "echo ", 5))
				ft_echo(data, cmd);
			else if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, " cd")
				|| !ft_strncmp(cmd, " cd ", 4) || !ft_strncmp(cmd, "cd ", 3))
				ft_cd(data, cmd);
			else if (!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, " pwd")
				|| !ft_strncmp(cmd, " pwd ", 5) || !ft_strncmp(cmd, "pwd ", 4))
				ft_pwd(data, cmd);
			else if (!ft_strcmp(cmd, "env") || !ft_strcmp(cmd, " env")
				|| !ft_strncmp(cmd, " env ", 5) || !ft_strncmp(cmd, "env ", 4))
				ft_env(data, cmd);
			else if (!ft_strcmp(cmd, "export") || !ft_strcmp(cmd, " export")
				|| !ft_strncmp(cmd, " export ", 8) || !ft_strncmp(cmd, "export ", 7))
				ft_export(data, cmd);
			else if (!ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, " unset")
				|| !ft_strncmp(cmd, " unset ", 7) || !ft_strncmp(cmd, "unset ", 6))
				ft_unset(data, cmd);
			else
				ft_exec(data, ast);
			free(cmd);
			cmd = NULL;
			free_ast(ast);
			ast = NULL;
		}
		free(line);
		line = NULL;
		line = readline(PROMPT);
	}
	rl_clear_history();
	free(cmd);
	cmd = NULL;
	free_ast(ast);
	ast = NULL;
	free(line);
	line = NULL;
}
