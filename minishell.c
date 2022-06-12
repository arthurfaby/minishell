#include "minishell.h"

/*
* -------------------------
* Function: path_finder
* ------------------------- 
*
*	Get the PATH value in env variable
*
* Params:
*	char **envp			: env variable from start
*
* Returns:
*	char *(*envp + 5)	: PATH value
*
* -------------------------
*/
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
	free_data(&data);
	return (0);
}
