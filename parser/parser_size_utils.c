#include "minishell.h"

void	get_size_error_code(int *index, int *size)
{
	(*size) += ft_intlen(g_data->status);
	(*index)++;
}

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

void	get_size_white_spaces(char *line, int *index, int *size)
{
	*index = skip_whitespace(line, *index);
	(*size)++;
}

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
