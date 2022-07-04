/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:55:52 by vnaud             #+#    #+#             */
/*   Updated: 2022/07/04 10:55:53 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: check_builtin
* ------------------------- 
*
*	compare user input with builtin name
*
* Params:
*	char	*line			: user input
*	char	*cmd			: user input parsed
*	t_ast	*ast			: AST
*
* Returns:
*	int		(0)				: user input is not a builtin
*	int		(error_code)	: error code from builtin function
*
* -------------------------
*/
int	check_builtin(char *line, char *cmd, t_ast *ast)
{
	if (!ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, " exit")
		|| !ft_strncmp(cmd, " exit ", 6) || !ft_strncmp(cmd, "exit ", 5))
		return (ft_exit(line, cmd, ast), 1);
	else if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, " echo")
		|| !ft_strncmp(cmd, " echo ", 6) || !ft_strncmp(cmd, "echo ", 5))
		return (ft_echo(cmd), 1);
	else if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, " cd")
		|| !ft_strncmp(cmd, " cd ", 4) || !ft_strncmp(cmd, "cd ", 3))
		return (ft_cd(cmd), 1);
	else if (!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, " pwd")
		|| !ft_strncmp(cmd, " pwd ", 5) || !ft_strncmp(cmd, "pwd ", 4))
		return (ft_pwd(cmd), 1);
	else if (!ft_strcmp(cmd, "env") || !ft_strcmp(cmd, " env")
		|| !ft_strncmp(cmd, " env ", 5) || !ft_strncmp(cmd, "env ", 4))
		return (ft_env(cmd), 1);
	else if (!ft_strcmp(cmd, "export") || !ft_strcmp(cmd, " export")
		|| !ft_strncmp(cmd, " export ", 8) || !ft_strncmp(cmd, "export ", 7))
		return (ft_export(cmd), 1);
	else if (!ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, " unset")
		|| !ft_strncmp(cmd, " unset ", 7) || !ft_strncmp(cmd, "unset ", 6))
		return (ft_unset(cmd), 1);
	return (0);
}

/*
* -------------------------
* Function: choose_execution
* ------------------------- 
*
*	Choose execution of builtin or execve
*
* Params:
*	char	*line	: user input
*	char	*cmd	: user input parsed
*	t_ast	**ast	: AST
*
* -------------------------
*/
void	choose_execution(char *line, char *cmd, t_ast **ast)
{
	*ast = tokenizer(cmd, *ast);
	if (!check_builtin(line, cmd, *ast))
		ft_exec(*ast);
	free(cmd);
	cmd = NULL;
	free_ast(*ast);
	*ast = NULL;
}

/*
* -------------------------
* Function: display_prompt
* ------------------------- 
*
*	display minishell prompt
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
					choose_execution(line, cmd, &ast);
			}
		}
		free(line);
		line = NULL;
		line = readline(PROMPT);
	}
	free_all(line, cmd, ast);
}
