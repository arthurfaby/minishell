#include "minishell.h"

char	*path_finder(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1)
		ft_usage_err(argv[0], "");
	init_data(&data, envp);
	init_sig();
	display_prompt(&data);
	free(data.cmd);
	ft_sstrdel(data.commands);
	ft_sstrdel(data.redirections);
	ft_sstrdel(data.metachars);
	ft_sstrdel(data.path);
	return (0);
}
