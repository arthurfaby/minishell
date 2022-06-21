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
	int		i;

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
				ft_cd(line);
			else if (ft_strnstr(line, "pwd", 3))
				ft_pwd();
			else if (ft_strcmp(line, "env") == 0)
				ft_env(data);
			else if (ft_strnstr(line, "export", 6))
				ft_export(data, line);
			else if (ft_strnstr(line, "unset", 5))
				ft_unset(data, line);
			cmd = parser(line);
			ast = tokenizer(cmd, ast);
			ft_exec(data, ast);
			free(cmd);
			cmd = NULL;
		}
		free(line);
		line = NULL;
		free_ast(ast);
			/*else if (ft_strnstr(line, "export", 7))
			{
				i = 0;
				while (line[i] && line[i] != ' ')
					i++;
				add_env(data, line + i + 1);
				//ft_printf("%s\n", get_env_value(data, line + i + 1));
			}
			else if (ft_strnstr(line, "unset", 6))
			{
				i = 0;
				while (line[i] && line[i] != ' ')
					i++;
				remove_env(data, line + i + 1);
			}
			else if (ft_strnstr(line, "cd", 3))
			{
				i = 0;
				while (line[i] && line[i] != ' ')
					i++;
				ft_cd(line + i + 1, data);
			}
			else if (ft_strnstr(line, "pwd", 4))
				ft_pwd(data);
			else if (ft_strnstr(line, "ls", 3))
			{
				char	**tes;
				tes = malloc(16);
				tes[0] = "/usr/bin/ls";
				tes[1] = 0;
				execve("/usr/bin/ls", tes, data->envp); 
			}
		}
		free(line);
		line = NULL;
		free_cmd_stack(data);*/
		line = readline(PROMPT);
	}
	rl_clear_history();
	free(line);
	line = NULL;
}
