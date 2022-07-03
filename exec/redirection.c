#include "minishell.h"

/*
* -------------------------
* Function: fill_docfile
* ------------------------- 
*
*	open and read to heredoc
*
* Params:
*	char	*eof	: EOF str
*
* Returns:
*	int (0)			: open error
*	int	(1)			: everything is ok
*
* -------------------------
*/
int	fill_docfile(char *eof)
{
	char	*line;
	int		heredoc;

	heredoc = open("heredoc", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (heredoc < 0)
		return (0);
	write(1, "> ", 2);
	line = get_next_line(0);
	while (ft_strncmp(eof, line, ft_strlen(eof))
		|| line[ft_strlen(eof)] != '\n')
	{
		write(heredoc, line, ft_strlen(line));
		free(line);
		write(1, "> ", 2);
		line = get_next_line(0);
	}
	free(line);
	close(heredoc);
	return (1);
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
int	get_input_redirect(t_cmd *cmd, int index)
{
	if (cmd->node->left->value[index][0] == '<'
		&& cmd->node->left->value[index][1] == '<')
	{
		if (cmd->infile >= 0)
			close(cmd->infile);
		if (!fill_docfile(cmd->node->left->value[index] + 2))
			return (1);
		cmd->infile = open("heredoc", O_RDONLY);
		if (cmd->infile < 0)
			return (perror(strerror(errno)), 1);
	}
	else if (cmd->node->left->value[index][0] == '<')
	{
		if (cmd->infile >= 0)
			close(cmd->infile);
		cmd->infile = open(&cmd->node->left->value[index][1], O_RDONLY);
		if (cmd->infile < 0)
			return (perror(strerror(errno)), 1);
	}
	return (0);
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
int	get_output_redirect(t_cmd *cmd, int index)
{
	if (cmd->node->left->value[index][0] == '>'
		&& cmd->node->left->value[index][1] == '>')
	{
		if (cmd->outfile >= 0)
			close(cmd->outfile);
		cmd->outfile = open(&cmd->node->left->value[index][2],
				O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
		if (cmd->outfile < 0)
			return (perror(strerror(errno)), 1);
	}
	else if (cmd->node->left->value[index][0] == '>')
	{
		if (cmd->outfile >= 0)
			close(cmd->outfile);
		cmd->outfile = open(&cmd->node->left->value[index][1],
				O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
		if (cmd->outfile < 0)
			return (perror(strerror(errno)), 1);
	}
	return (0);
}

/*
* -------------------------
* Function: get_redirect
* ------------------------- 
*
*	Open redirections files until last one
*
* Params:
*	t_cmd *cmd	: cmd struct
*
* Returns:
*	int (1)	: error redirections files
*	int (0)	: redirections opened
*
* -------------------------
*/
int	get_redirect(t_cmd *cmd)
{
	int		index;

	index = -1;
	while (cmd->node->left->value[++index])
	{
		if (get_input_redirect(cmd, index))
			return (1);
		if (get_output_redirect(cmd, index))
			return (1);
	}
	return (0);
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
void	redirect_check(t_cmd *cmd)
{
	int	ret;

	ret = get_redirect(cmd);
	if (ret == 1)
		exit(1);
}
