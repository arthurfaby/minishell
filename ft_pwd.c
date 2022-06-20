#include "minishell.h"

void	ft_pwd(t_data *data)
{
	(void) data;
	ft_printf("%s\n", getenv("PWD"));
}
