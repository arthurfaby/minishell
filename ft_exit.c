#include "minishell.h"

void	ft_exit(t_data *data, char *line, char *cmd, t_ast *ast)
{
	int	i;
	int	ret;

	i = 0;
	while (ft_iswhitespace(cmd[i]))
		i++;
	i += 5;
	ret = (short int)ft_atoi(cmd + i);
	free(line);
	line = NULL;
	free(cmd);
	cmd = NULL;
	free_ast(ast);
	ast = NULL;
	free_data(data);
	exit(ret);	
}
