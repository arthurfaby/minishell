#include "minishell.h"

/*
* -------------------------
* Function: new_var
* ------------------------- 
*
*	parse the input line of the user into a new struct (t_var)
*
* Params:
*	char *str 	: input line of the user
*
* Returns:
*	NULL 		: malloc error
*	t_var *new	: struct parse
*
* -------------------------
*/
t_var	*new_var(char *str)
{
	t_var	*new;

	new = malloc(sizeof(t_var));
	if (!new)
		return (NULL);
	new->name = create_name(str);
	new->value = create_value(str);
	if (!new->name || !new->value)
	{
		free(new);
		free(new->name);
		free(new->value);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

/*
* -------------------------
* Function: var_add_last 
* ------------------------- 
*
*	add a new variable at the end of the linked list
*
* Params:
*	t_var	**lst	: address of the first variable
*	t_var 	*new	: new variable to add
*
* Returns:
*	void
*
* -------------------------
*/
void	var_add_last(t_var **lst, t_var *new)
{
	t_var	*tmp;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/*
* -------------------------
* Function: check_dup
* ------------------------- 
*
*	check if the variable to add is already in the linked list
*
*	if the variable is already in the linked list, it will replace
*	the value
*
* Params:
*	t_var	**lst	: address of the first variable
*	t_var	*new	: new variable to check
*
* Returns:
*	int (0)			: variable not found
*	int (1)			: variable found
*
* -------------------------
*/
int	check_dup(t_var **lst, t_var *new)
{
	t_var	*tmp;
	char	*old;

	if (!lst)
		return (0);
	tmp = *lst;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, new->name) == 0)
		{
			old = tmp->value;
			tmp->value = new->value;
			free(old);
			free(new->name);
			free(new);
			return (1);
		}
		tmp = tmp->next;
	}
	free(new->name);
	free(new->value);
	free(new);
	return (0);
}

/*
* -------------------------
* Function: add_env
* ------------------------- 
*
*	parse and add a variable to the linked list
*
*	if the variable is already in the linked list]
*	the function do nothing
*
* Params:
*	char	*str	: input line of the user
*	t_data	*data	: datas of minishell
*
* Returns:
*	void
*
* -------------------------
*/
void	add_env(char *str, t_data *data)
{
	if (!check_dup(&data->env, new_var(str)))
		var_add_last(&data->env, new_var(str));
}

/*
* -------------------------
* Function: remove_env 
* ------------------------- 
*
*	remove a variable from env based on the name
*
* Params:
*	char	*name	: name of variable to remove
*	t_data	*data	: datas of minishell
*
* Returns:
*	void
*
* -------------------------
*/
void	remove_env(char *name, t_data *data)
{
	t_var	*tmp;
	t_var	*old;	

	if (!data->env)
		return ;
	tmp = data->env;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->next->name, name) == 0)
		{
			old = tmp->next;
			tmp->next = tmp->next->next;
			free(old->name);
			free(old->value);
			free(old);
			return ;
		}
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->name, name) == 0)
	{
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}
}
