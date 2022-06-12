#include "minishell.h"

/*
* -------------------------
* Function: ft_cd
* ------------------------- 
*
*	Change working directory
*
* Params:
*	char *path	: path directory
*
* -------------------------
*/
void	ft_cd(char *path)
{
	if (chdir(path) < 0)
		ft_putstr_fd(strerror(errno), 2);
}
