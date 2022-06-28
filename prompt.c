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
			if (ft_strncmp(cmd, "exit", 4) == 0 && (cmd[4] == ' ' || cmd[4] == 0))
				ft_exit(data, line, cmd, ast);
			else if (ft_strncmp(cmd, "echo ", 5) == 0)
				ft_echo(data, cmd);
			else if (ft_strncmp(cmd, "cd ", 3) == 0)
				ft_cd(data, cmd);
			else if (ft_strncmp(cmd, "pwd ", 4) == 0)
				ft_pwd(data);
			else if (ft_strcmp(cmd, "env") == 0)
				ft_env(data);
			else if (ft_strncmp(cmd, "export ", 7) == 0)
				ft_export(data, cmd);
			else if (ft_strncmp(line, "unset ", 6) == 0)
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
