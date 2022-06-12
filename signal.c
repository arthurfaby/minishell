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
	}
	else if (sigcode == 4)
		ft_printf("youpi");
}

/*
* -------------------------
* Function: init_sig
* ------------------------- 
*
*	Initialize signal handler
*
* Returns:
*	int	(0)		: No issues
*	int (-1)	: Error signal function
*
* -------------------------
*/
int	init_sig(void)
{
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		return (-1);
	if (signal(SIGQUIT, sig_handler) == SIG_ERR)
		return (-1);
	if (signal(4, sig_handler) == SIG_ERR)
		return (-1);
	return (0);
}
