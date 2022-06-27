#include "minishell.h"

/*
* -------------------------
* Function: free_node
* ------------------------- 
*
*	free t_node element
*
* Params:
*	t_node *node	: node to free
*
* -------------------------
*/
void	free_node(t_node *node)
{
	if (!node)
		return ;
	if (node->left)
	{
		ft_sstrdel(node->left->value);
		node->left->value = NULL;
		free(node->left);
		node->left = NULL;
	}
	if (node->right)
	{
		ft_sstrdel(node->right->value);
		node->right->value = NULL;
		free(node->right);
		node->right = NULL;
	}
	if (node->value)
	{
		ft_sstrdel(node->value);
		node->value = NULL;
	}
	free(node);
	node = NULL;
}

/*
* -------------------------
* Function: free_ast
* ------------------------- 
*
*	free t_ast element
*
* Params:
*	t_ast *ast	: ast to free
*
* -------------------------
*/
void	free_ast(t_ast *ast)
{
	t_node	*it;
	t_node	*tmp;

	it = ast->root;
	while (it)
	{
		if (it->type == 1)
		{
			free_node(it);
			it = NULL;
		}
		else
		{
			tmp = it;
			free_node(tmp->left);
			it = it->right;
			free(tmp);
			tmp = NULL;
		}
	}
	ast->root = NULL;
	free(ast);
}

/*
* -------------------------
* Function: free_env
* ------------------------- 
*
*	free env value in data struct
*
* Params:
*	t_data *data	: data struct
*
* -------------------------
*/
void	free_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		free(data->env[i]);
		data->env[i] = NULL;
		i++;
	}
	free(data->env);
}

/*
* -------------------------
* Function: free_data
* ------------------------- 
*
*	free data struct
*
* Params:
*	t_data *data	: data struct
*
* -------------------------
*/
void	free_data(t_data *data)
{
	//free_env(data);
	ft_sstrdel(data->path);
	ft_sstrdel(data->env);
}
