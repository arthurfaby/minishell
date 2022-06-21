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
void	ft_echo(char *option, char **args)
{
	if (option && ft_strcmp(option, "-n") == 0)
		while (*args)
			ft_putstr(*args++);
	else
		while (*args)
			ft_putendl(*args++);
}
