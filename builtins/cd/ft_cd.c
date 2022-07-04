/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:02:07 by afaby             #+#    #+#             */
/*   Updated: 2022/07/04 11:02:08 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* -------------------------
* Function: print_error_cd 
* ------------------------- 
*
*	print NSFOD error on stderr and set status to 1
*
* Params:
*	char	*path : path
*
* -------------------------
*/
void	print_error_cd(char *path)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	g_data->status = 1;
}

/*
* -------------------------
* Function: change_directory
* ------------------------- 
*
*	change to directory and update env
*
* Params:
*	DIR		*dir	: directory to go to
*	char	*path	: path
*
* -------------------------
*/
void	change_directory(DIR *dir, char *path)
{
	char	*tmp;
	char	pwd[2048];

	closedir(dir);
	chdir(path);
	getcwd(pwd, 2048);
	tmp = ft_strjoin("OLDPWD=", get_env_value("PWD"));
	add_env(tmp);
	free(tmp);
	tmp = ft_strjoin("PWD=", pwd);
	add_env(tmp);
	free(tmp);
	tmp = NULL;
	g_data->status = 0;
}

/*
* -------------------------
* Function: go_to_home
* ------------------------- 
*
*	move cwd to home
*
* Params:
*	char	*path	: path
*
* -------------------------
*/
void	go_to_home(char *path)
{
	DIR		*dir;	

	if (!path)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		g_data->status = 1;
		return ;
	}
	dir = opendir(path);
	if (errno == ENOENT)
		print_error_cd(path);
	else
		change_directory(dir, path);
}

/*
* -------------------------
* Function: ft_cd
* ------------------------- 
*
*	builtin function for cd command
*
* Params:
*	char	*path	: path to go to
*
* -------------------------
*/
void	ft_cd(char *path)
{
	DIR		*dir;

	path += 2;
	while (*path && ft_iswhitespace(*path))
		path++;
	if (!*path)
		go_to_home(get_env_value("HOME"));
	else
	{
		dir = opendir(path);
		if (errno == ENOENT)
			print_error_cd(path);
		else
			change_directory(dir, path);
	}
}
