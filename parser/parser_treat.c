/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_treat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:04:55 by afaby             #+#    #+#             */
/*   Updated: 2022/07/04 11:04:55 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: treat_error_code
* ------------------------- 
*
*	put error code in res
*
* Params:
*	char	*res		: user input parsed
*	int		*index		: index
*	int		*index_res	: index res
*
* -------------------------
*/
void	treat_error_code(char *res, int *index, int *index_res)
{
	int		index_tmp;
	char	*tmp;

	index_tmp = -1;
	tmp = ft_itoa(g_data->status);
	while (tmp[++index_tmp])
		res[(*index_res)++] = tmp[index_tmp];
	(*index)++;
	free(tmp);
	tmp = NULL;
}

/*
* -------------------------
* Function: treat_dollar
* ------------------------- 
*
*	treat dollar sign and parse it
*
* Params:
*	char	*res		: user input parsed
*	char	*line		: user input not parsed
*	int		*index		: index
*	int		*index_res	: index res
*
* -------------------------
*/
void	treat_dollar(char *res, char *line, int *index, int *index_res)
{
	char	*env_value;
	int		index_tmp;
	char	*tmp;

	(*index)++;
	if (line[*index] == '?')
	{
		treat_error_code(res, index, index_res);
	}
	else
	{
		index_tmp = *index;
		while (line[index_tmp] && ft_isalnum(line[index_tmp]))
			index_tmp++;
		tmp = ft_substr(line, *index, (index_tmp - *index));
		env_value = get_env_value(tmp);
		*index += (index_tmp - *index);
		free(tmp);
		tmp = NULL;
		while (env_value && *env_value)
			res[(*index_res)++] = *env_value++;
	}	
}

/*
* -------------------------
* Function: treat_simple_quotes
* ------------------------- 
*
*	treat simple quotes and parse it
*
* Params:
*	char	*res		: user input parsed
*	char	*line		: user input not parsed
*	int		*index		: index
*	int		*index_res	: index res
*
* -------------------------
*/
void	treat_simple_quotes(char *res, char *line, int *index, int *index_res)
{
	(*index)++;
	while (line[*index] && line[*index] != '\'')
		res[(*index_res)++] = line[(*index)++];
	(*index)++;
}

/*
* -------------------------
* Function: treat_white_spaces
* ------------------------- 
*
*	treat white spaces and parse it
*
* Params:
*	char	*res		: user input parsed
*	char	*line		: user input not parsed
*	int		*index		: index
*	int		*index_res	: index res
*
* -------------------------
*/
void	treat_white_spaces(char *res, char *line, int *index, int *index_res)
{
	res[(*index_res)++] = ' ';
	*index = skip_whitespace(line, *index);
}

/*
* -------------------------
* Function: treat_double_quotes
* ------------------------- 
*
*	treat double quotes and parse it
*
* Params:
*	char	*res		: user input parsed
*	char	*line		: user input not parsed
*	int		*index		: index
*	int		*index_res	: index res
*
* -------------------------
*/
void	treat_double_quotes(char *res, char *line, int *index, int *index_res)
{
	(*index)++;
	while (line[*index] && line[*index] != '"')
	{
		if (line[*index] == '$')
			treat_dollar(res, line, index, index_res);
		else
			res[(*index_res)++] = line[(*index)++];
	}
	(*index)++;
}
