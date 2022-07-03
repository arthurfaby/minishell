#include "minishell.h"

void	ft_pwd(char *cmd)
{
	(void)cmd;
	ft_printf("%s\n", get_env_value("PWD"));
}
