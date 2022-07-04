#include "minishell.h"

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
