/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:06:49 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/28 19:03:14 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh.h"

static void	cd_shaping_env(char *str)
{
	char	**split;
	char	pwd[PATH_MAX];
	char	*var_pwd;
	int		i;

	getcwd(pwd, PATH_MAX);
	split = ft_strsplit(str, '/');
	i = -1;
	while (split[++i])
	{
		if (!ft_strcmp(split[i], ".."))
			ft_strrchr(pwd, '/') != pwd ? (*ft_strrchr(pwd, '/') = '\0') :
				(*(ft_strrchr(pwd, '/') + 1) = '\0');
		else if (!ft_strcmp(split[i], "."))
			NULL;
		else
		{
			if (!(pwd[0] == '/' && pwd[1] == '\0'))
				ft_strcat(pwd, "/");
			ft_strcat(pwd, split[i]);
		}
		chdir(pwd);
		(var_pwd = get_env("PWD=", VAL)) ? ft_strcpy(var_pwd, pwd) : 0;
	}
	ft_strlst_del(&split, i + 1);
}

static void	cd_path_finder(t_cmd *c)
{
	char	*old;
	char	pwd[PATH_MAX];
	char	*var_pwd;

	if (!there_is_d(c))
		return ;
	if (c->av[1][0] == '/')
	{
		ft_strcpy(pwd, c->av[1]);
		chdir(pwd);
		if ((old = get_env("OLDPWD=", VAL)))
			ft_strcpy(old, pwd);
		if ((var_pwd = get_env("PWD=", VAL)))
			ft_strcpy(var_pwd, pwd);
	}
	else
		cd_shaping_env(c->av[1]);
}

static void	cd_no_arg(void)
{
	char	*var_pwd;
	char	pwd[PATH_MAX];
	char	*home;
	char	*old;

	if (!(home = get_env("HOME=", VAL)))
		return (ft_putstr("cd: HOME not set\n"));
	getcwd(pwd, PATH_MAX);
	if ((old = get_env("OLDPWD=", VAL)))
		ft_strcpy(old, pwd);
	if ((var_pwd = get_env("PWD=", VAL)))
		ft_strcpy(pwd, home);
	chdir(home);
}

static void	cd_exchange(void)
{
	char	pwd[PATH_MAX];
	char	*old;
	char	*var_pwd;
	char	*temp;

	temp = (char*)malloc(PATH_MAX);
	temp[0] = '\0';
	if ((old = get_env("OLDPWD=", VAL)))
	{
		getcwd(pwd, PATH_MAX);
		ft_strcpy(temp, pwd);
		if ((var_pwd = get_env("PWD=", VAL)))
			ft_strcpy(var_pwd, old);
		ft_strcpy(pwd, old);
		chdir(pwd);
		ft_strcpy(old, temp);
	}
	else
		ft_putstr("cd: OLDPWD not set\n");
	ft_strdel(&temp);
}

void		ft_cd(t_cmd *c)
{
	if (c->ac == 1)
		cd_no_arg();
	else if (!ft_strcmp(c->av[1], "-"))
		cd_exchange();
	else
		cd_path_finder(c);
}
