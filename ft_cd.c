#include "minishell.h"

/*
* -------------------------
* Function: print_error_cd 
* ------------------------- 
*
*	print NSFOD error on stderr and set status to 1
*
* Params:
*	t_data	*data : minishell datas
*	char	*path : path
*
* -------------------------
*/
void	print_error_cd(t_data *data, char *path)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	data->status = 1;
}

void	go_to_home(t_data *data, char *path)
{
	DIR		*dir;	
	char	*tmp;
	char	pwd[2048];
	
	if (!path)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		data->status = 1;
		return ;
	}
	dir = opendir(path);
	if (errno == ENOENT)
		print_error_cd(data, path);
	else
	{
		ft_printf("change to : %s\n", path);
		closedir(dir);
		chdir(path);
		getcwd(pwd, 2048);
		tmp = ft_strjoin("OLDPWD=", get_env_value(data, "PWD"));
		add_env(data, tmp);
		free(tmp);
		tmp = ft_strjoin("PWD=", pwd);
		add_env(data, tmp);
		free(tmp);
		tmp = NULL;
		data->status = 0;
	}
}

/*
* -------------------------
* Function: ft_cd
* ------------------------- 
*
*	builtin function for cd command
*
* Params:
*	t_data	*data	: minishell datas
*	char	*path	: path to go to
*
* -------------------------
*/
void	ft_cd(t_data *data, char *path)
{
	char	*tmp;
	DIR		*dir;
	char	pwd[2048];

	path += 2;
	while (*path && ft_iswhitespace(*path))
		path++;
	ft_printf("path : |%d|\n", *path);
	if (!*path)
		go_to_home(data, get_env_value(data, "HOME"));
	else
	{
		dir = opendir(path);
		if (errno == ENOENT)
			print_error_cd(data, path);
		else
		{
			closedir(dir);
			chdir(path);
			getcwd(pwd, 2048);
			tmp = ft_strjoin("OLDPWD=", get_env_value(data, "PWD"));
			add_env(data, tmp);
			free(tmp);
			tmp = ft_strjoin("PWD=", pwd);
			add_env(data, tmp);
			free(tmp);
			tmp = NULL;
			data->status = 0;
		}
	}
}
