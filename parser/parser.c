/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:55:58 by vnaud             #+#    #+#             */
/*   Updated: 2022/07/04 10:55:59 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: parser
* ------------------------- 
*
*	parse the user input into tokenizable line
*
* Params:
*	char	*line	: user input
*
* Returns:
*	char	*res	: parsed user input
*
* -------------------------
*/
char	*parser(char *line)
{
	int		index;
	char	*res;
	int		index_res;

	res = ft_calloc(sizeof(char), get_size_cmd(line) + 1);
	if (!res)
		return (NULL);
	index_res = 0;
	index = skip_whitespace(line, 0);
	while (line[index])
	{
		if (line[index] == '"')
			treat_double_quotes(res, line, &index, &index_res);
		else if (line[index] == '\'')
			treat_simple_quotes(res, line, &index, &index_res);
		else if (ft_iswhitespace(line[index]))
			treat_white_spaces(res, line, &index, &index_res);
		else if (line[index] == '$')
			treat_dollar(res, line, &index, &index_res);
		else
			res[index_res++] = line[index++];
	}
	res = spaces_redirections(res);
	return (res);
}
