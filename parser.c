/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:20:19 by vnaud             #+#    #+#             */
/*   Updated: 2022/06/01 21:31:52 by vnaud            ###   ########.fr       */
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

char *get_str(char **sstr, char *word)
{
	while (*sstr)
	{
		if (!ft_strcmp(*sstr, word))
			return (*sstr);
		sstr++;
	}
	return (NULL);
}

int	parser(t_data *data, char *cmd)
{
	int		index_start;
	int		index_end;
	char	*tmp;
	t_elem	*new;

	index_start = skip_whitespace(cmd, 0);
	index_end = index_start;
	while (cmd[index_end] && cmd[index_start])
	{
		while (cmd[index_end] && !ft_iswhitespace(cmd[index_end]))
			index_end++;
		tmp = ft_substr(cmd, index_start, (index_end - index_start));
		if (isinsstr(data->commands, tmp))
		{
			new = new_elem(ft_strdup(get_str(data->commands, tmp)), COMMAND);
			add_elem_cmd(data, new);
		}
		else if (isinsstr(data->redirections, tmp))
		{
			new = new_elem(ft_strdup(get_str(data->redirections, tmp)), REDIRECTION);
			add_elem_cmd(data, new);
		}
		else if (isinsstr(data->metachars, tmp))
		{
			new = new_elem(ft_strdup(get_str(data->metachars, tmp)), METACHAR);
			add_elem_cmd(data, new);
		}
		else
		{
			new = new_elem(ft_strdup(tmp), VALUE);
			add_elem_cmd(data, new);
		}
		free(tmp);
		index_start = skip_whitespace(cmd, index_end);
		index_end = index_start;
	}
	return (0);
}
