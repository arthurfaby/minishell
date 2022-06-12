#include "minishell.h"

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
	t_var	*tmp;
	t_var	*old;

	tmp = data->env;
	while (tmp)	
	{
		old = tmp;
		tmp = tmp->next;
		free(old->name);
		free(old->value);
		free(old);
	}
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
	free_env(data);
	ft_sstrdel(data->path);
}
