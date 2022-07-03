#include "minishell.h"

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

void	treat_simple_quotes(char *res, char *line, int *index, int *index_res)
{
	(*index)++;
	while (line[*index] && line[*index] != '\'')
		res[(*index_res)++] = line[(*index)++];
	(*index)++;
}

void	treat_white_spaces(char *res, char *line, int *index, int *index_res)
{
	res[(*index_res)++] = ' ';
	*index = skip_whitespace(line, *index);
}

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
