#include "minishell.h"

/*
* -------------------------
* Function: free_all
* ------------------------- 
*
*	free all malloc datas
*
* Params:
*	t_data	*data	: minishell datas
*	char	*line	: input line
*	char	*cmd	: parsed line
*	t_ast	*ast	: ast
*
* -------------------------
*/
void	free_all(char *line, char *cmd, t_ast *ast)
{
	free(line);
	line = NULL;
	free(cmd);
	cmd = NULL;
	free_ast(ast);
	ast = NULL;
	free_data();
	rl_clear_history();
}

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

	if (!ast)
		return ;
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
void	free_data(void)
{
	ft_sstrdel(g_data->env);
	free(g_data->builtins);
	free(g_data);
}
