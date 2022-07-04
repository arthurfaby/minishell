/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:14:57 by afaby             #+#    #+#             */
/*   Updated: 2022/07/04 11:14:58 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: path_finder
* ------------------------- 
*
*	Get the PATH value in env variable
*
* Params:
*	char **envp			: env variable from start
*
* Returns:
*	char *(*envp + 5)	: PATH value
*
* -------------------------
*/
char	*path_finder(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1)
		ft_usage_err(argv[0], "");
	init_data(envp);
	create_handler();
	display_prompt();
	ft_printf("exit\n");
	return (0);
}
