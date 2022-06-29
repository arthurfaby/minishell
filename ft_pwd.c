#include "minishell.h"

void	ft_pwd(t_data *data, char *cmd)
{
	(void)cmd;
	ft_printf("%s\n", get_env_value(data, "PWD"));
}
