/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:56:04 by vnaud             #+#    #+#             */
/*   Updated: 2022/07/04 10:56:05 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: get_size_cmd
* ------------------------- 
*
*	get size of user input parsed
*
* Params:
*	char	*line	: user input
*
* Returns:
*	int	size		: size of user input parsed
*
* -------------------------
*/
int	get_size_cmd(char *line)
{
	int		index;
	int		size;

	size = 0;
	index = skip_whitespace(line, 0);
	while (line[index])
	{
		if (line[index] == '"')
			get_size_double_quotes(line, &index, &size);
		else if (line[index] == '\'')
			get_size_simple_quotes(line, &index, &size);
		else if (ft_iswhitespace(line[index]))
			get_size_white_spaces(line, &index, &size);
		else if (line[index] == '$')
			get_size_dollar(line, &index, &size);
		else
		{
			size++;
			index++;
		}
	}
	return (size);
}
