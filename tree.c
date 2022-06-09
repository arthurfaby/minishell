#include "minishell.h"

t_node	*new_node(int type)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (new);
	new->type = type;
	new->value = NULL;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void	add_left(t_node *node, t_node *new)
{
	if (!node)
		return ;
	node->left = new;
	new->parent = node;
}

void	add_right(t_node *node, t_node *new)
{
	if (!node)
		return ;
	node->right = new;
	new->parent = node;
}
