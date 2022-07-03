#include "minishell.h"

/*
* -------------------------
* Function: isnumeric
* ------------------------- 
*
*	check if an arg is made of digit
*
* Params:
*	char	*arg	: arg to check
*
* Returns:
*	int	(0)			: not numeric
*	int	(1)			: numeric
*
* -------------------------
*/
int	isnumeric(char *arg)
{
	int		i;

	i = -1;
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
			return (0);
	return (1);
}

/*
* -------------------------
* Function: size_split
* ------------------------- 
*
*	get size of a split
*
* Params:
*	char	**split	: args of exit
*
* Returns:
*	int				: size of split
*
* -------------------------
*/
int	size_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

/*
* -------------------------
* Function: check_errors
* ------------------------- 
*
*	check and print errors for exit
*
* Params:
*	char	**split : args of exit
*	int		i		: size of split
*
* Returns:
*	int (2)			: numeric error
*	int	(-1)		: too many args error
*	int				: exit status
*
* -------------------------
*/
int	check_errors(char **split, int i)
{
	if (!isnumeric(split[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(split[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (2);
	}
	else if (i > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		ft_sstrdel(split);
		return (-1);
	}
	else
		return (ft_atoi(split[1]));
}

/*
* -------------------------
* Function: ft_exit
* ------------------------- 
*
*	execute exit builtin
*
* Params:
*	t_data	*data	: minishell datas
*	char	*line	: input line
*	char	*cmd	: parsed line
*	t_ast	*ast	: ast
*
* -------------------------
*/
void	ft_exit(t_data *data, char *line, char *cmd, t_ast *ast)
{
	int		i;
	int		ret;
	char	**split;

	ret = data->status;
	split = ft_split(cmd, ' ');
	i = size_split(split);
	ft_putstr_fd("exit\n", 2);
	if (i != 1)
	{
		ret = check_errors(split, i);
		if (ret == -1)
			return ;
	}
	free_all(data, line, cmd, ast);
	ft_sstrdel(split);
	exit(ret);
}
