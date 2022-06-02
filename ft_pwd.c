#include "minishell.h"

void	ft_pwd(void)
{
	ft_printf("%s\n", getenv("PWD"));
}
