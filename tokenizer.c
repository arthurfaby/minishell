#include "minishell.h"

/*
* -------------------------
* Function: tokenizer
* ------------------------- 
*
*	tokenize the parsed string
*
* Params:
*	char *cmd	: command parsed
*	t_ast *ast	: AST of the command
*
* Returns:
*	t_ast *ast	: tokenized command
*
* -------------------------
*/
t_ast	*tokenizer(char *cmd, t_ast *ast)
{
	int		size;
	char	**pipe;
	t_node	*it;

	pipe = ft_split(cmd, '|');
	if (!pipe)
		return (NULL);
	size = 0;
	while (pipe[size])
		size++;
	if (size > 1)
	{
		ast->root = new_node(PIPE, NULL);
		it = ast->root;
		size--;
		while (size--)
		{
			add_right(it, new_node(PIPE, NULL));
			it = it->right;
		}
	}
	if (size == 1)
	{
		ast->root = new_node(COMMAND, get_content(pipe[0]));
		ft_sstrdel(pipe);
		split_args_redirect(ast);
		return (ast);
	}
	size = 0;
	it = ast->root;
	while (pipe[size])
	{
		add_left(it, new_node(COMMAND, get_content(pipe[size])));
		it = it->right;
		size++;
	}
	ft_sstrdel(pipe);
	split_args_redirect(ast);
	return (ast);
}
