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

	ast = malloc(sizeof(t_ast));
	if (!ast)
		return ;
	ast->root = NULL;
	line = readline(PROMPT);
	while (line)
	{
		if (*line)
		{
			add_history(line);
			if (ft_strcmp(line, "exit") == 0)
				break ;
			else if (ft_strcmp(line, "env") == 0)
				ft_env(data);
			else if (ft_strnstr(line, "export", 6))
				ft_export(data, line);
			else if (ft_strnstr(line, "unset", 5))
				ft_unset(data, line);
			cmd = parser(line);
			ast = tokenizer(cmd, ast);
			free(cmd);
			cmd = NULL;
		}
		free(line);
		line = NULL;
		free_ast(ast);
		line = readline(PROMPT);
	}
	rl_clear_history();
	free(line);
	line = NULL;
	free_ast(ast);
	free(ast);
	ast = NULL;
}
