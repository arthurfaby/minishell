#include "minishell.h"

char	*get_cmd(t_data *data)
{
	int		index;
	char	*cmd;
	char	*tmp;

	index = -1;
	while (data->path[++index])
	{
		tmp = ft_strjoin(data->path[index], "/");
		cmd = ft_strjoin(tmp, data->cmd->head->value);
		free(tmp);
		tmp = NULL;
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		cmd = NULL;
	}
	if (access(data->cmd->head->value, 0))
		return (data->cmd->head->value);
	return (NULL);
}

void	child(t_data *data, char *cmd)
{
	char	**args;
	t_elem	*it;
	int		index;

	args = malloc(sizeof(char *) * (data->cmd->size + 1));
	if (!args)
		exit(EXIT_FAILURE);
	args[data->cmd->size] = NULL;
	it = data->cmd->head;
	index = 0;
	while (it)
	{
		if (index == 0)
		{
			args[index] = ft_strdup(cmd);
			if (!args[index])
				exit(EXIT_FAILURE);
		}
		else
		{
			args[index] = ft_strdup(it->value);
			if (!args[index])
				exit(EXIT_FAILURE);
		}
		it = it->next;
		index++;
	}
	execve(args[0], args, data->envp);
}

void	exec_cmd(t_data *data)
{
	pid_t	pid;
	char	*cmd;
	int		status;

	if (data->cmd->head->type != 0)
	{
		ft_printf("First param is not a command please be gentle :D!\n");
		return ;
	}
	cmd = get_cmd(data);
	if (!cmd)
		return ;
	pid = fork();
	if (pid < 0)
	{
		ft_printf("Error: fork in exec_cmd!\n");
		return ;
	}
	if (pid == 0)
	{
		child(data, cmd);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, &status, 0);
	free(cmd);
}
