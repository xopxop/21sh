/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:30:45 by tango             #+#    #+#             */
/*   Updated: 2020/08/05 06:11:49 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	print_21sh_usr(void)
{
	char *usr;

	ft_putstr(MGTA);
	ft_putstr(BOLD);
	ft_putstr("21sh ");
	ft_putstr(INIT);
	if ((usr = get_env("USER=", VAL)))
	{
		ft_putstr(SKYB);
		ft_putstr(usr);
	}
	ft_putstr(" ");
}

static void	print_cwd(void)
{
	char pwd[PATH_MAX];
	char *home;

	getcwd(pwd, PATH_MAX);
	ft_putstr(YELW);
	ft_putstr("[");
	if ((home = get_env("HOME=", VAL)))
	{
		if (!ft_strcmp(pwd, home))
			ft_putstr(pwd);
		else if (ft_strstr(pwd, home))
		{
			ft_putstr("~");
			ft_putstr(ft_strstr_e(pwd, home));
		}
		else
			ft_putstr(pwd);
	}
	else
		ft_putstr(pwd);
	ft_putstr("]");
}

void		get_prompt(void)
{
	print_21sh_usr();
	print_cwd();
	ft_putstr(INIT);
	ft_putstr("\n> ");
}
