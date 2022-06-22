#include "minishell.h"

/*
* -------------------------
* Function: ft_unset
* ------------------------- 
*
*	unset env variable
*
* Params:
*	t_data *data	: data struct
* 	char *line		: user input line
*
* -------------------------
*/
void	ft_unset(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	remove_env(data, line + i + 1);
}
