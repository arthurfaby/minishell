/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:04:43 by afaby             #+#    #+#             */
/*   Updated: 2022/07/04 11:04:44 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: get_number_pipe
* ------------------------- 
*
*	return the number of pipe in command AST
*
* Params:
*	t_ast *ast	: AST from command
*
* Returns:
*	int nb_pipe	: number of pipe
*
* -------------------------
*/
int	get_number_pipe(t_ast *ast)
{
	int		nb_pipe;
	t_node	*it;

	it = ast->root;
	nb_pipe = 0;
	while (it)
	{
		if (it->type == 0)
			nb_pipe++;
		it = it->right;
	}
	return (nb_pipe);
}

/*
* -------------------------
* Function: open_pipe
* ------------------------- 
*
*	malloc and open pipe
*
* Params:
*	t_cmd	*cmd	: cmd struct
*
* -------------------------
*/
void	open_pipe(t_cmd *cmd)
{
	int	index;

	index = -1;
	while (++index < cmd->nb_cmd - 1)
	{
		cmd->pipe[index] = malloc(sizeof(int) * 2);
		if (!cmd->pipe[index])
			return ;
		if (pipe(cmd->pipe[index]) < 0)
			return ;
	}
}

/*
* -------------------------
* Function: close_pipe
* ------------------------- 
*
*	close all different pipes
*
* Params:
*	t_cmd	*cmd	: cmd struct
*	int		id		: id of the process
*
* -------------------------
*/
void	close_pipe(t_cmd *cmd, int id)
{
	int	index;

	index = -1;
	while (++index < cmd->nb_cmd - 1)
	{
		if (id == 0 && index == 0)
			close(cmd->pipe[index][0]);
		else if (id == cmd->nb_cmd - 1 && index == cmd->nb_cmd - 2)
			close(cmd->pipe[index][1]);
		else if (id == 0 || id == cmd->nb_cmd - 1)
		{
			close(cmd->pipe[index][0]);
			close(cmd->pipe[index][1]);
		}
		else if (index == id - 1)
			close(cmd->pipe[index][1]);
		else if (index == id)
			close(cmd->pipe[index][0]);
		else
		{
			close(cmd->pipe[index][0]);
			close(cmd->pipe[index][1]);
		}
	}
}

/*
* -------------------------
* Function: free_pipe
* ------------------------- 
*
*	free all pipes
*
* Params:
*	t_cmd	*cmd	: cmd
*
* -------------------------
*/
void	free_pipe(t_cmd *cmd)
{
	int	index;

	index = -1;
	while (++index < cmd->nb_cmd - 1)
		free(cmd->pipe[index]);
	free(cmd->pipe);
}
