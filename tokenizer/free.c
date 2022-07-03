#include "minishell.h"

char	**free_before(void **args, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(args[size]);
		args[size] = NULL;
		i++;
	}
	free(args);
	return (NULL);
}

void	free_trio(char **split, char **args, char **redirect)
{
	ft_sstrdel(split);
	ft_sstrdel(args);
	ft_sstrdel(redirect);
}
