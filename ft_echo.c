#include "minishell.h"

/*
* -------------------------
* Function: ft_echo 
* ------------------------- 
*
*	Print args like bash "echo" function
*
* Params:
*	char *option	: option -n or empty
*	char **args		: args to print with ft_echo
*
* -------------------------
*/
void	ft_echo(char *cmd)
{
	int	option;

	option = 0;
	while (ft_iswhitespace(*cmd))
		cmd++;
	cmd += 5;
	while (ft_strncmp(cmd, "-n", 2) == 0 && (cmd[2] == ' ' || !cmd[2]))
	{
		cmd += 3;
		option = 1;
	}
	if (option)
		ft_putstr(cmd);
	else
	{
		ft_putstr(cmd);
		ft_putchar('\n');
	}
	data->status = 0;
}
