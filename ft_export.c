#include "minishell.h"

/*
* -------------------------
* Function: ft_export
* ------------------------- 
*
* Create/Modify env variable
*
* Params:
*	t_data *data	: data struct
*	char *line		: user input line
*
* -------------------------
*/
void	ft_export(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	add_env(line + i + 1, data);
}
