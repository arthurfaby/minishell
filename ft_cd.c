#include "minishell.h"

void	ft_cd(char *path, t_data *data)
{
	(void)data;
	ft_printf("change to : %s\n", path);
	chdir(path);
}
