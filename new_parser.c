//#include "minishell.h"

void	treat_error_code(

void	treat_dollar(char *res, char *line, int *index, int *index_res)
{
	char	*env_value;
	int		index_tmp;
	char	*tmp;

	*index++;
	if (line[*index] == '?')
	{
		tmp = ft_itoa(data->status);
		while (*tmp)
			res[*index_res++] = *tmp++;
		size++;//itoa data->status
		*index++;// increase index 
		// free(tmp); // FREE TMP` WITHOUT tmp++
		// tmp = NULL;
	}
	else
	{
		index_tmp = *index;
		while (line[index_tmp] && ft_isalnum(line[index_tmp]))
		index_tmp++;
		tmp = ft_substr(line, *index, (index_tmp - *index));
		env_value = get_env_value(data, tmp);
		*index += (index_tmp - *index);
		free(tmp);
		tmp = NULL;
		while (env_value && *env_value)
			res[*index_res++] = *env_value++;
	}	

}

void	treat_double_quotes(char *res, char *line, int *index, int *index_res)
{
	int		index_tmp;
	char	*tmp;
	char	*env_value;

	if (line[*index] == '$')
		// treat dollar
	else
		res[*index_res++] = line[*index++];
}

char	*parser(t_data *data, char *line)
{
	int		index;
	char	*res;
	int		index_res;

	res = ft_calloc(sizeof(char), get_size_cmd(data, line) + 1);
	if (!res)
		return (NULL);
	index_res = 0;
	index = skip_whitespace(line, 0);
	while (line[index])
	{
		if (line[index] == '"')
			treat_double_quotes(res, line, &index, &index_res);
		else if (line[index] == '\'')
			// treat simple quotes
		else if (ft_iswhitespace(line[index]))
			// treat white spaces
		else if (line[index] == '$')
			// treat dollar
		else
			res[index_res++] = line[index++];
	}
	res = spaces_redirections(res);
	return (res);
}
