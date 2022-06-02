#include "minishell.h"

void	ft_cd(char *path)
{
	if (chdir(path) < 0)
		ft_putstr_fd(strerror(errno), 2);
}
