#include "minishell.h"

void	ft_pwd(t_data *data)
{
	ft_printf("%s\n", get_env_value(data, "PWD"));
}
