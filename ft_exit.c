#include "minishell.h"

int	check_arg_exit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_error_exit(t_data *data, char *cmd)
{
	char	**args;
	int		j;
	int		ret;

	ret = -1;
	j = -1;
	args = ft_split(cmd, ' ');
	if (!args || !*args)
		return (free(args), data->status);
	while (args[++j])
	{
		if (j >= 1)
		{
			ft_putstr_fd("minishell: exit: too many arguments.\n", 2);
			ft_sstrdel(args);
			return (-1);
		}
		if (!check_arg_exit(args[j]))
		{	
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(args[j], 2);
			ft_putstr_fd(": numeric argument required.\n", 2);
			ret = 2;
			break;
		}
	}
	if (ret == -1)
		ret = (short int)ft_atoi(args[0]);
	ft_sstrdel(args);
	return (ret);
		
}

void	ft_exit(t_data *data, char *line, char *cmd, t_ast *ast)
{
	int	i;
	int	ret;

	i = 0;
	while (ft_iswhitespace(cmd[i]))
		i++;
	i += 4;
	ft_putstr_fd("exit\n", 2);
	ret = check_error_exit(data, cmd + i);
	if (ret == -1)
	{
		data->status = 1;
		return ;
	}
	free(line);
	line = NULL;
	free(cmd);
	cmd = NULL;
	free_ast(ast);
	ast = NULL;
	free_data(data);
	exit(ret);	
}
