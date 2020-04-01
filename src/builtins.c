/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:27:24 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/28 19:03:02 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh.h"

void		ft_env(void)
{
	int		i;

	i = -1;
	while (g_env[++i])
	{
		ft_putstr(g_env[i]);
		ft_putstr("\n");
	}
}

void		ft_pwd(void)
{
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
	ft_putstr(pwd);
	ft_putstr("\n");
}

void		ft_exit(t_cmd *coms, int opt)
{
	t_cmd	*c_p;
	int		i;

	if (opt == PRINT)
		!coms ? ft_putstr("\nlogout\n") : ft_putstr("logout\n");
	while (coms)
	{
		c_p = coms;
		coms = coms->next;
		cmd_del(c_p);
	}
	i = -1;
	while (g_env[++i])
		ft_strdel(&g_env[i]);
	ft_strdel(&g_env[i]);
	free(g_env);
	opt == ER ? exit(-1) : exit(0);
}

void		ft_echo(t_cmd *c)
{
	int		i;

	i = 0;
	while (++i < c->ac)
	{
		ft_putstr(c->av[i]);
		if (i + 1 != c->ac && ft_strcmp(c->av[i], ""))
			ft_putstr(" ");
	}
	ft_putchar('\n');
}
