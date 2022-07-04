#include "minishell.h"

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
