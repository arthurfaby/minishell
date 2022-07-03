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
	if (!res)
		return (NULL);//free
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
						tmp = ft_itoa(g_data->status);
						while (*tmp)
							res[index_res++] = *tmp++;
						size++;//itoa data->status
						index++;// increase index 
						// free(tmp); // FREE TMP WITHOUT tmp++
						// tmp = NULL;
					}
					else
					{
						index_tmp = index;
						while (line[index_tmp] && ft_isalnum(line[index_tmp]))
							index_tmp++;
						tmp = ft_substr(line, index, (index_tmp - index));
						env_value = get_env_value(tmp);
						index += (index_tmp - index);
						free(tmp);
						tmp = NULL;
						while (env_value && *env_value)
							res[index_res++] = *env_value++;
					}
				}
				else
				{
					res[index_res++] = line[index++];
				}
			}
			index++;
		}
		else if (line[index] == '\'')
		{
			index++;
			while (line[index] && line[index] != '\'')
				res[index_res++] = line[index++];
			index++;
		}
		else if (ft_iswhitespace(line[index]))
		{
			res[index_res++] = ' ';
			index = skip_whitespace(line, index);
		}
		else if (line[index] == '$')
		{
			index++;
			if (line[index] == '?')
			{
				tmp = ft_itoa(g_data->status);
				while (*tmp)
					res[index_res++] = *tmp++;
				size++;//itoa data->status
				index++; //increase index
				// free(tmp); // FREE TMP WITHOUT tmp++
				// tmp = NULL;
			}
			else
			{
				index_tmp = index;
				while (line[index_tmp] && ft_isalnum(line[index_tmp]))
					index_tmp++;
				tmp = ft_substr(line, index, (index_tmp - index));
				env_value = get_env_value(tmp);
				index += index_tmp;
				free(tmp);
				tmp = NULL;
				while (env_value && *env_value)
					res[index_res++] = *env_value++;
			}
		}
		else
		{
			while (line[index] && line[index] != '"' && line[index] != '\''
				&& !ft_iswhitespace(line[index]) && line[index] != '$')
				res[index_res++] = line[index++];
		}
	}
	res[index_res] = '\0';
	res = spaces_redirections(res);
	return (res);
}
