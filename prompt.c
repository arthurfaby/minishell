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
void	display_prompt(void)
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
				cmd = parser(line);
				if (cmd)
				{
					ast = tokenizer(cmd, ast);
          if (!ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, " exit")
            || !ft_strncmp(cmd, " exit ", 6) || !ft_strncmp(cmd, "exit ", 5))
            ft_exit(line, cmd, ast);
          else if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, " echo")
            || !ft_strncmp(cmd, " echo ", 6) || !ft_strncmp(cmd, "echo ", 5))
            ft_echo(cmd);
          else if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, " cd")
            || !ft_strncmp(cmd, " cd ", 4) || !ft_strncmp(cmd, "cd ", 3))
            ft_cd(cmd);
          else if (!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, " pwd")
            || !ft_strncmp(cmd, " pwd ", 5) || !ft_strncmp(cmd, "pwd ", 4))
            ft_pwd(cmd);
          else if (!ft_strcmp(cmd, "env") || !ft_strcmp(cmd, " env")
            || !ft_strncmp(cmd, " env ", 5) || !ft_strncmp(cmd, "env ", 4))
            ft_env(cmd);
          else if (!ft_strcmp(cmd, "export") || !ft_strcmp(cmd, " export")
            || !ft_strncmp(cmd, " export ", 8) || !ft_strncmp(cmd, "export ", 7))
            ft_export(cmd);
          else if (!ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, " unset")
            || !ft_strncmp(cmd, " unset ", 7) || !ft_strncmp(cmd, "unset ", 6))
            ft_unset(cmd);
					else
						ft_exec(ast);
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
	free_all(line, cmd, ast);
}
