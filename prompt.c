/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:09:16 by vnaud             #+#    #+#             */
/*   Updated: 2022/06/01 13:52:54 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_prompt(t_data *data)
{
	char	*line;

	(void)data;
	line = readline("mshell >> ");
	while (1)
	{
		if (ft_strcmp(line, "exit") == 0)
		{
			free(line);
			break ;
		}
		free(line);
		line = readline("mshell >> ");
	}
}
