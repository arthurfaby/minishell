/*
* -------------------------
* Function: 
* ------------------------- 
*
*
*
* Params:
*
*
* Returns:
*
*
* -------------------------
*/
void	first_child(t_data *data, char **argv, char **envp, int id)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile < 0)
	{
		free_main(data);
		ft_err_msg(strerror(errno));
	}
	close_pipe(data, id);
	dup2(data->pp[id][1], 1);
	dup2(data->infile, 0);
	data->args_child = ft_split(argv[2], ' ');
	data->cmd = get_cmd(data, envp);
	if (!data->cmd)
	{
		free_child(data, 1);
		ft_err_msg("Error: command not found");
	}
	execve(data->cmd, data->args_child, envp);
}

/*
* -------------------------
* Function: 
* ------------------------- 
*
*
*
* Params:
*
*
* Returns:
*
*
* -------------------------
*/
void	mid_child(t_data *data, char **argv, char **envp, int id)
{
	int		status;

	waitpid(data->child_pid[id - 1], &status, 0);
	close_pipe(data, id);
	dup2(data->pp[id][1], 1);
	dup2(data->pp[id - 1][0], 0);
	data->args_child = ft_split(argv[id + 2], ' ');
	data->cmd = get_cmd(data, envp);
	if (!data->cmd)
	{
		free_child(data, 2);
		ft_err_msg("Error: command not found");
	}
	execve(data->cmd, data->args_child, envp);
}

/*
* -------------------------
* Function: 
* ------------------------- 
*
*
*
* Params:
*
*
* Returns:
*
*
* -------------------------
*/
void	last_child(t_data *data, char **argv, char **envp, int id)
{
	int		status;

	data->outfile = open(argv[data->nb_cmd + 2], 00001101, S_IWUSR | S_IRUSR);
	if (data->outfile < 0)
	{
		free_main(data);
		ft_err_msg(strerror(errno));
	}
	waitpid(data->child_pid[id - 1], &status, 0);
	close_pipe(data, id);
	dup2(data->outfile, 1);
	dup2(data->pp[id - 1][0], 0);
	data->args_child = ft_split(argv[id + 2], ' ');
	data->cmd = get_cmd(data, envp);
	if (!data->cmd)
	{
		free_child(data, 3);
		ft_err_msg("Error: command not found");
	}
	execve(data->cmd, data->args_child, envp);
}

/*
* -------------------------
* Function: 
* ------------------------- 
*
*
*
* Params:
*
*
* Returns:
*
*
* -------------------------
*/
void	create_child(t_data *data, char **argv, char **envp)
{
	int	index;

	index = -1;
	while (++index < data->nb_cmd)
	{
		data->child_pid[index] = fork();
		if (data->child_pid[index] < 0)
			ft_err_msg(strerror(errno));
		else if (index == 0 && data->child_pid[index] == 0)
			first_child(data, argv, envp, index);
		else if (index == data->nb_cmd - 1 && data->child_pid[index] == 0)
			last_child(data, argv, envp, index);
		else if (data->child_pid[index] == 0)
			mid_child(data, argv, envp, index);
	}
}
