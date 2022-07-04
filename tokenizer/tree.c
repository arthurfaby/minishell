/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:55:29 by vnaud             #+#    #+#             */
/*   Updated: 2022/07/04 10:55:31 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: new_node
* ------------------------- 
*
*	Create a new node for the AST
*
* Params:
*	int		type		: type of node
*	char	**content	: content of node
*
* Returns:
*	t_node	*new		: new node
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
