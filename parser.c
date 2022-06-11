#include "minishell.h"

/*
* -------------------------
* Function: parser
* ------------------------- 
*
*	parse user input line
*
* Params:
*	char *line	: user input line
*
* Returns:
*	char *cmd	: parsed command
*
* -------------------------
*/
char	*parser(char *line)
{
	char	*res;
	int		index;
	int		size;
	int		index_res;
	char	*tmp;
	int		index_tmp;
	char	*env_value;

	index_res = 0;
	size = get_size_cmd(line);
	res = malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	index = skip_whitespace(line, 0);
	while (line[index])
	{
		if (line[index] == '"')
		{
			index++;
			while (line[index] && line[index] != '"')
			{
				if (line[index] == '$')
				{
					index++;
					if (line[index] == '?')
					{
						size++;
						index++;
					}
					else
					{
						index_tmp = index;
						while (line[index_tmp] && ft_isalnum(line[index_tmp]))
							index_tmp++;
						tmp = ft_substr(line, index, (index_tmp - index + 1));
						//env_value = getenv_value(tmp);
						free(tmp);
						tmp = NULL;
					}
				while (*env_value)
					res[index_res++] = *env_value++;
				}
				else
				{
					res[index_res++] = line[index++];
				}
			}
		}
		else if (line[index] == '\'')
		{
			index++;
			while (line[index] && line[index] != '\'')
				res[index_res++] = line[index++];
		}
		else if (ft_iswhitespace(line[index]))
		{
			res[index_res++] = ' ';
			index = skip_whitespace(line, index);
		}
		else
		{
			while (line[index] && line[index] != '"' && line[index] != '\''
					&& !ft_iswhitespace(line[index]))
				res[index_res++] = line[index++];
		}
	}
	res = spaces_redirections(res);
	return (res);
}
