/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:55:20 by vnaud             #+#    #+#             */
/*   Updated: 2022/07/04 10:55:23 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: set_unique_cmd
* ------------------------- 
*
*	set unique command in ast
*
* Params:
*	t_ast	*ast	: Abstract Syntax Tree
*	char	**pipe	: split on pipe value of user input command
*
* Returns:
*	t_ast *ast		: Ast with the new element
*
* -------------------------
*/
t_ast	*set_unique_cmd(t_ast *ast, char **pipe)
{
	ast->root = new_node(COMMAND, get_content(pipe[0]));
	ft_sstrdel(pipe);
	split_args_redirect(ast);
	return (ast);
}

/*
* -------------------------
* Function: set_multi_cmd 
* ------------------------- 
*
*	set multi cmds in ast
*
* Params:
*	t_ast	*ast	: Abstract Syntax Tree
*	char	**pipe	: user input split on pipe to split each commands
*
* -------------------------
*/
void	set_multi_cmd(t_ast *ast, char **pipe)
{
	int		size;
	t_node	*it;

	size = 0;
	it = ast->root;
	while (pipe[size])
	{
		add_left(it, new_node(COMMAND, get_content(pipe[size])));
		it = it->right;
		size++;
	}
}

/*
* -------------------------
* Function: split_args_redirect
* ------------------------- 
*
*	split commands into redirections and args
*
* Params:
*	t_ast *ast	: AST of commands
*
* -------------------------
*/
void	split_args_redirect(t_ast *ast)
{
	t_node	*it;

	it = ast->root;
	while (it)
	{
		if (it->type != 0)
		{
			fill_nodes(it);
			break ;
		}
		fill_nodes(it->left);
		it = it->right;
	}
}
