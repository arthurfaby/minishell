/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:09:16 by vnaud             #+#    #+#             */
/*   Updated: 2022/06/01 21:28:08 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cmd_stack(t_data *data)
{
	t_elem	*it;

	it = data->cmd->head;
	while (it)
	{
		ft_printf("type = %d, id = %d, value = %s\n", it->type, it->id, it->value);
		it = it->next;
	}
}

void	free_cmd_stack(t_data *data)
{
	t_elem	*it;
	t_elem	*tmp;

	it = data->cmd->head;
	while (it)
	{
		free(it->value);
		it->value = NULL;
		tmp = it;
		it = it->next;
		free(tmp);
		tmp = NULL;
	}
	data->cmd->head = NULL;
}

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
		if (!parser(data, line))
			print_cmd_stack(data);
		free(line);
		line = NULL;
		free_cmd_stack(data);
		ft_printf("mshell>> ");
		line = get_next_line(0);
	}
}
