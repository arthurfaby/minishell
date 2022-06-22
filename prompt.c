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
	//int		i;

	line = readline(PROMPT);
	while (line)
	{
		if (*line)
		{
			add_history(line);
			if (ft_strcmp(line, "exit") == 0)
				break ;
			else if (ft_strnstr(line, "echo", 4))
				ft_echo(NULL, NULL);
			else if (ft_strnstr(line, "cd", 2))
				ft_cd(data, line + 3);
			else if (ft_strnstr(line, "pwd", 3))
				ft_pwd(data);
			else if (ft_strcmp(line, "env") == 0)
				ft_env(data);
			else if (ft_strnstr(line, "export", 6))
				ft_export(data, line);
			else if (ft_strnstr(line, "unset", 5))
				ft_unset(data, line);
			cmd = parser(line);
			ast = tokenizer(cmd, ast);
			//ft_exec(data, ast);
			free(cmd);
			cmd = NULL;
		}
		free(line);
		line = NULL;
		free_ast(ast);
		ast = NULL;
		line = readline(PROMPT);
	}
	rl_clear_history();
	free_ast(ast);
	ast = NULL;
	free(line);
	line = NULL;
}
