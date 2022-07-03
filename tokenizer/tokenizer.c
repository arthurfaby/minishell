#include "minishell.h"

int	fill_ast(t_ast *ast, int size)
{
	t_node	*it;

	ast->root = new_node(PIPE, NULL);
	it = ast->root;
	size--;
	while (size--)
	{
		add_right(it, new_node(PIPE, NULL));
		it = it->right;
	}
	return (size);
}

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

	ast = malloc(sizeof(t_ast));
	if (!ast)
		return (NULL);
	pipe = ft_split(cmd, '|');
	if (!pipe)
		return (free(ast), NULL);
	size = 0;
	while (pipe[size])
		size++;
	if (size > 1)
		size = fill_ast(ast, size);
	if (size == 1)
		return (set_unique_cmd(ast, pipe));
	set_multi_cmd(ast, pipe);
	ft_sstrdel(pipe);
	split_args_redirect(ast);
	return (ast);
}

void	fill_nodes(t_node *it)
{
	char	**split;
	char	**args;
	char	**redirect;

	split = NULL;
	args = NULL;
	redirect = NULL;
	if (!it)
		return ;
	split = ft_split(it->value[0], ' ');
	args = get_split_args(split, args);
	redirect = get_split_redirect(split, redirect);
	it->left = new_node(REDIRECTION, ft_sstrdup(redirect));
	it->right = new_node(ARGS, ft_sstrdup(args));
	free_trio(split, args, redirect);
}
