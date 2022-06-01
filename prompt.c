/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:09:16 by vnaud             #+#    #+#             */
/*   Updated: 2022/06/01 08:29:55 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_prompt(t_data *data)
{
	char	*line;

	(void)data;
	ft_printf("mshell>> ");
	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "exit\n") == 0)
		{
			free(line);
			break ;
		}
		ft_printf("Type \"exit\" to quit!\n");
		free(line);
		ft_printf("mshell>> ");
		line = get_next_line(0);
	}
}
