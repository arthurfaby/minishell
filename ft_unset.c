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
void	ft_unset(char *line)
{
	while (ft_iswhitespace(*line))
		line++;
	line += 6;
	if (ft_strchr(line, '='))
	{
		ft_putstr_fd("minishell: unset: '", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		data->status = 1;
		return ;
	}
	remove_env(line);
}
