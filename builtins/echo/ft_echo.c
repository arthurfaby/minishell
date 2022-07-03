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
	while (*cmd && ft_iswhitespace(*cmd))
		cmd++;
	cmd += 4;
	while (*cmd && ft_iswhitespace(*cmd))
		cmd++;
	while (ft_strncmp(cmd, "-n", 2) == 0 && (cmd[2] == ' ' || !cmd[2]))
	{
		if (cmd[2] == ' ')
			cmd += 3;
		else
			cmd += 2;
		option = 1;
	}
	ft_putstr(cmd);
	if (!option)
		ft_putchar('\n');
	g_data->status = 0;
}
