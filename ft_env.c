#include "minishell.h"

void	ft_env(char	**envp)
{
	while (*envp)
		ft_printf("%s\n", *envp++);
}
