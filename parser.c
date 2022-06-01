/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:20:19 by vnaud             #+#    #+#             */
/*   Updated: 2022/06/01 15:16:42 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_whitespace(char *cmd, int index_start)
{
	while (cmd[index_start] && ft_iswhitespace(cmd[index_start]))
		index_start++;
	return (index_start);
}

int	isinsstr(char **sstr, char *word)
{
	while (*sstr)
	{
		if (!ft_strcmp(*sstr, word))
			return (1);
		sstr++;
	}
	return (0);
}

int	get_str(char **sstr, char *word)
{
	while (*sstr)
	{
		if (!ft_strcmp(*sstr, word))
			return (1);
		sstr++;
	}
	return (0);
}

int	parser(t_data *data, char *cmd)
{
	int		index_start;
	int		index_end;
	char	*tmp;
	t_new	*new;

	index_start = skip_whitespace(cmd, 0);
	index_end = index_start;
	while (cmd[index_end] && cmd[index_start])
	{
		while (cmd[index_end] && !ft_iswhitespace(cmd[index_end]))
			index_end++;
		tmp = ft_substr(cmd, index_start, (index_end - index_start + 1));
		if (isinsstr(data->commands, tmp))
		{
			new = new_elem(find(data->commands, tmp), COMMAND);
			add_elem_cmd(data, new);
		}
		else if (isinsstr(data->redirections, tmp))
		{
			add_elem_cmd(data, tmp);
		}
		else if (isinsstr(data->metachars, tmp))
		{
			add_elem_cmd(data, tmp);
		}
		else
		{
			add_elem_cmd(data, tmp);
		}
		free(tmp);
	}
	return (0);
}
