#include "minishell.h"

/*
* -------------------------
* Function: sig_handler
* ------------------------- 
*
*	handle received signal
*
* Params:
*	int	sigcode	: signal id
*
* -------------------------
*/
void	sig_handler(int sigcode)
{
	if (sigcode == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_data->status = 130;
	}
}

/*
* -------------------------
* Function:  delete_handler
* ------------------------- 
*
*	delete handler on signals
*
* -------------------------
*/
void	delete_handler(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

/*
* -------------------------
* Function:  ignore_handler
* ------------------------- 
*
*	ignore handler on signals
*
* -------------------------
*/
void	ignore_handler(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

/*
* -------------------------
* Function: create_handler
* ------------------------- 
*
*	Initialize signal handler
*
* -------------------------
*/
void	create_handler(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

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
