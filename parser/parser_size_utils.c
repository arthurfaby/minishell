/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_size_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <vnaud@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:56:16 by vnaud             #+#    #+#             */
/*   Updated: 2022/07/04 11:25:18 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: get_size_error_code
* ------------------------- 
*
*	get size of status error value
*
* Params:
*	int	*index	: index
*	int	*index	: size
*
* -------------------------
*/
void	get_size_error_code(int *index, int *size)
{
	(*size) += ft_intlen(g_data->status);
	(*index)++;
}

/*
* -------------------------
* Function: get_size_dollar
* ------------------------- 
*
*	get size of env value or error code
*
* Params:
*	char	*line	: user input
*	int		*index	: index
*	int		*size	: size
*
* -------------------------
*/
void	get_size_dollar(char *line, int *index, int *size)
{
	char	*env_value;
	int		index_tmp;
	char	*tmp;

	(*index)++;
	if (line[*index] == '?')
		get_size_error_code(index, size);
	else
	{
		index_tmp = *index;
		while (line[index_tmp] && ft_isalnum(line[index_tmp]))
			index_tmp++;
		tmp = ft_substr(line, *index, (index_tmp - *index));
		env_value = get_env_value(tmp);
		free(tmp);
		tmp = NULL;
		(*size) += ft_strlen(env_value);
		(*index) += (index_tmp - *index);
	}	
}

/*
* -------------------------
* Function: get_size_simple_quotes
* ------------------------- 
*
*	get size simple quoted input
*
* Params:
*	char	*line	: user input
*	int		*index	: index
*	int		*size	: size
*
* -------------------------
*/
void	get_size_simple_quotes(char *line, int *index, int *size)
{
	(*index)++;
	while (line[*index] && line[*index] != '\'')
	{
		(*size)++;
		(*index)++;
	}
	(*index)++;
}

/*
* -------------------------
* Function: get_size_white_spaces
* ------------------------- 
*
*	get size white spaces input
*
* Params:
*	char	*line	: user input
*	int		*index	: index
*	int		*size	: size
*
* -------------------------
*/
void	get_size_white_spaces(char *line, int *index, int *size)
{
	*index = skip_whitespace(line, *index);
	(*size)++;
}

/*
* -------------------------
* Function: get_size_double_quotes
* ------------------------- 
*
*	get size double quoted user input
*
* Params:
*	char	*line	: user input
*	int		*index	: index
*	int		*size	: size
*
* -------------------------
*/
void	get_size_double_quotes(char *line, int *index, int *size)
{
	(*index)++;
	while (line[*index] && line[*index] != '"')
	{
		if (line[*index] == '$')
			get_size_dollar(line, index, size);
		if (line[*index] && line[*index] != '$' && line[*index] != '"')
			(*size)++;
		(*index)++;
	}
}
