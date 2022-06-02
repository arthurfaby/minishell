#include "minishell.h"

void	ft_echo(char *option, char **args)
{
	if (option && ft_strcmp(option, "-n") == 0)
		while (*args)
			ft_putstr(*args++);
	else
		while(*args)
			ft_putendl(*args++);
}
