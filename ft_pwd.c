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
void	ft_pwd(void)
{
	ft_printf("%s\n", getenv("PWD"));
}
