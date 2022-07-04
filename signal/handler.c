/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:55:43 by vnaud             #+#    #+#             */
/*   Updated: 2022/07/04 10:55:44 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
