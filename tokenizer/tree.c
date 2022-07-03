#include "minishell.h"

/*
* -------------------------
* Function: new_node
* ------------------------- 
*
*	Create a new node for the AST
*
* Params:
*	int	type		: type of node
*	char **content	: content of node
*
* Returns:
*	t_node *new		: new node
*
* -------------------------
*/
t_node	*new_node(int type, char **content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (new);
	new->type = type;
	new->value = content;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/*
* -------------------------
* Function: add_left
* ------------------------- 
*
*	add new to the left branch of the node
*
* Params:
*	t_node *node	: node parent
*	t_node *new		: node to add
*
* -------------------------
*/
void	add_left(t_node *node, t_node *new)
{
	if (!node)
		return ;
	node->left = new;
	new->parent = node;
}

/*
* -------------------------
* Function: add_right
* ------------------------- 
*
*	add new to the right branch of the node
*
* Params:
*	t_node *node	: node parent
*	t_node *new		: node to add
*
* -------------------------
*/
void	add_right(t_node *node, t_node *new)
{
	if (!node)
		return ;
	node->right = new;
	new->parent = node;
}
