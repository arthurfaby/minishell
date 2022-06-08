#include "minishell.h"

int	skip_whitespace(char *cmd, int index_start)
{
	while (cmd[index_start] && ft_iswhitespace(cmd[index_start]))
		index_start++;
	return (index_start);
}

char	*spaces_redirections(char *cmd)
{
	int		index;
	int		index_res
	char	*res;
	int		size;

	index = -1;
	index_res = 0;
	size = ft_strlen(cmd); // If (!cmd || !cmd[0]) return (cmd)
	while (cmd[++index])
	{
		if (cmd[index] == '<' || cmd[index] == '>')
			if (cmd[index + 1] == ' ')
				size--;
		else if ((cmd[index] == '<' && cmd[index + 1] == '<') || (cmd[index] == '>' && cmd[index + 1] == '>'))
			if (cmd[index + 2] == ' ')
				size--;
	}
	res = malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	index = -1;
	while (cmd[++index])
	{
		if (cmd[index] == '<' || cmd[index] == '>')
			if (cmd[index + 1] == ' ')
				res[index_res++] = cmd[index++];
			else
				res[index_res++] = cmd[index];
		else if ((cmd[index] == '<' && cmd[index + 1] == '<') || (cmd[index] == '>' && cmd[index + 1] == '>'))
			if (cmd[index + 2] == ' ')
			{
				res[index_res++] = cmd[index++];
				res[index_res++] = cmd[index++];
			}
			else
			{
				res[index_res++] = cmd[index++];
				res[index_res++] = cmd[index];
			}
		else
			res[index_res++] = cmd[index++];
	}
	free(cmd);
	cmd = NULL;
	return (res);
}

int	get_size_cmd(char *line)
{
	int		index;
	int		size;
	char	*tmp;
	int		index_tmp;
	char	*env_value;

	size = 0;
	index = skip_whitespaces(line, 0);
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
						env_value = getenv_value(tmp);
						free(tmp);
						tmp = NULL;
						size += ft_strlen(env_value);
					}
				}
			}
		}
		else if (line[index] == ''')
		{
			index++;
			while (line[index] && line[index] != ''')
			{
				size++;
				index++;
			}
		}
		else if (ft_iswhitespaces(line[index]))
		{
			index = skip_whitespaces(line, index);
			size++;
		}
		else
		{
			index++;
			while (line[index] && line[index] != '"' && line[index] != '''
					&& !ft_iswhitespaces(line[index]))
			{
				size++;
				index++;
			}
		}
	}
	return (size);
}
