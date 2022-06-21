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
void	ft_cd(char *path, t_data *data)
{
	(void)data;
	ft_printf("change to : %s\n", path);
	chdir(path);
}
