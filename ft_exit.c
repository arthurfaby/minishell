#include "minishell.h"

void	free_ft_exit(t_data *data, char *line, char *cmd, t_ast *ast)
{
	free(line);
	line = NULL;
	free(cmd);
	cmd = NULL;
	free_ast(ast);
	ast = NULL;
	free_data(data);
	rl_clear_history();
}

int	isnumeric(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
			return (0);
	return (1);
}

int	size_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	ft_exit(t_data *data, char *line, char *cmd, t_ast *ast)
{
	int	i;
	int	ret;
	char	**split;

	ret = data->status;
	split = ft_split(cmd, ' ');
	i = size_split(split);
	if (i != 1)
	{
		if (!isnumeric(split[1]))
		{//redirect printf on stderr (2)
			ft_printf("exit\nminishell: exit: %s: numeric argument required\n", split[1]);
			ret = 2;
		}
		else if (i > 2)
		{
			ft_putstr_fd("exit\nminishell: exit: too many arguments\n", 2);
			ft_sstrdel(split);
			return ;
		}
		else
			ret = ft_atoi(split[1]);
	}
	free_ft_exit(data, line, cmd, ast);
	ft_sstrdel(split);
	exit(ret);
}
