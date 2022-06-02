/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:33:24 by afaby             #+#    #+#             */
/*   Updated: 2022/06/01 15:03:07 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int	sigcode)
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

