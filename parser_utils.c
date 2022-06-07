#include "minishell.h"

int	skip_whitespace(char *cmd, int index_start)
{
	while (cmd[index_start] && ft_iswhitespace(cmd[index_start]))
		index_start++;
	return (index_start);
}

int	isinsstr(char **sstr, char *word)
{
	while (*sstr)
	{
		if (!ft_strcmp(*sstr, word))
			return (1);
		sstr++;
	}
	return (0);
}

char	*get_str(char **sstr, char *word)
{
	while (*sstr)
	{
		if (!ft_strcmp(*sstr, word))
			return (*sstr);
		sstr++;
	}
	return (NULL);
}
