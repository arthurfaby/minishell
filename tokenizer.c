#include "minishell.h"

t_ast	*tokenizer(char *cmd, t_ast *ast)
{
	// split on pipe
	// create tree with every element of split on right node
	// split node on space to get redirections input, command, args, redirections output
	// create node with command and params of this command on the left node of the tree
	// Hope that will work properly KEKW
	int		size;
	char	**pipe;
	t_node	*it;

	pipe = ft_split(cmd, '|');
	if (!pipe)
		return (NULL); // split return NULL
	size = 0;
	while (pipe[size])
		size++;
	if (size > 1)
	{
		ast->root = new_node(PIPE);
		it = ast->root;
		size--;
		while (size--)
		{
			add_right(it, new_node(PIPE));
			it = it->right;
		}
	}
	if (size == 1)
	{
		ast->root = new_node(COMMAND);
		ft_sstrdel(pipe);
		return (ast);
	}
	size = 0;
	it = ast->root;
	while (pipe[size] && it)
	{
		add_left(it, new_node(COMMAND));
		it = it->right;
	}
	ft_sstrdel(pipe);
	return (ast);
}
