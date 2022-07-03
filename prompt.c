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
			if (!(skip_whitespace(line, 0) == (int)ft_strlen(line)))
			{
				cmd = parser(data, line);
				if (cmd)
				{
					ast = tokenizer(cmd, ast);
					if (!ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, " exit")
						|| !ft_strncmp(cmd, " exit ", 6) || !ft_strncmp(cmd, "exit ", 5))
						ft_exit(data, line, cmd, ast);
					else if (!ft_strncmp(cmd, "echo ", 5))
						ft_echo(data, cmd);
					else if (!ft_strncmp(cmd, "cd ", 3))
						ft_cd(data, cmd);
					else if (!ft_strncmp(cmd, "pwd ", 4))
						ft_pwd(data, cmd);
					else if (!ft_strcmp(cmd, "env"))
						ft_env(data, cmd);
					else if (!ft_strncmp(cmd, "export ", 7))
						ft_export(data, cmd);
					else if (!ft_strncmp(line, "unset ", 6))
						ft_unset(data, cmd);
					else
						ft_exec(data, ast);
					free(cmd);
					cmd = NULL;
					free_ast(ast);
					ast = NULL;
				}
			}
		}
		free(line);
		line = NULL;
		line = readline(PROMPT);
	}
	free_all(data, line, cmd, ast);
}
