#include "minishell.h"

void	ft_cd(t_data *data, char *path)
{
	char	*tmp;
	char	pwd[500];

	if (ft_strcmp(path, ".") == 0)
		return ;
	if (ft_strcmp(path, "-") == 0)
		chdir(get_env_value(data, "OLDPWD"));
	else
		chdir(path);
	getcwd(pwd, 500);
	tmp = ft_strjoin("OLDPWD=", get_env_value(data, "PWD"));
	add_env(data, tmp);
	free(tmp);
	tmp = ft_strjoin("PWD=", pwd);
	add_env(data, tmp);
	free(tmp);
	tmp = NULL;
}
