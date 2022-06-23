#include "minishell.h"

int	check_line_export(char *line)
{
	int	i;

	i = 0;
	if (!isalpha(line[i]))
		return (0);
	while (line[i] && isalnum(line[i]))
		i++;
	if (line[i] != '=')
		return (0);
	return (1);
}

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
	while (ft_iswhitespace(*line))
		line++;
	line += 7;
	if (!check_line_export(line))
		return ;
	add_env(data, line);
	data->status = 0;
}
