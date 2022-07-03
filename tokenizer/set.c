#include "minishell.h"

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
*	t_ast	*ast : ast
*
*
* Returns:
*
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
