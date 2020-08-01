#include "minishell.h"

void		set_OLDPWD(char pwd[PATH_MAX])
{
	t_exe	*cmd;

	getcwd(pwd, PATH_MAX);
	cmd = (t_exe*)ft_memalloc(sizeof(t_exe));
	cmd->av = (char**)ft_memalloc(sizeof(char*) * 2);
	cmd->av[0] = ft_strdup("setenv");
	cmd->av[1] = ft_strnew(7 + ft_strlen(pwd));
	cmd->av[1] = ft_strcpy(cmd->av[1], "OLDPWD=");
	cmd->av[1] = ft_strcat(cmd->av[1], pwd);
	cmd->ac = 2;
	ft_setenv(cmd);
	ft_strlst_del(&cmd->av, 2);
	free(cmd);
}