#include "minishell.h"

/*
* -------------------------
* Function: ft_pwd
* ------------------------- 
*
*	Print path to working directory
*
* -------------------------
*/
void	ft_pwd(t_data *data)
{
	(void) data;
	ft_printf("%s\n", getenv("PWD"));
}
