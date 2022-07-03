#include "minishell.h"

/*
* -------------------------
* Function: message_signal 
* ------------------------- 
*
*	print special message in case of status
*
* Params:
*	int	status	: status of execve
*
* -------------------------
*/
void	message_signal(int status)
{
	if (status == 2)
		ft_printf("\n");
	else if (status == 131)
		ft_printf("Quit (core dumped)\n");
}

void	convert_signal(void)
{
	if (g_data->status == 256)
		g_data->status = 1;
	else if (g_data->status == 65280 || g_data->status == 32512)
		g_data->status = 127;
	else if (g_data->status == 512)
		g_data->status = 2;
	else if (g_data->status == 2)
		g_data->status = 130;
}
