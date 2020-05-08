/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:27:24 by ihwang            #+#    #+#             */
/*   Updated: 2020/05/08 01:51:05 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void		ft_exit(t_exe *exe, int opt)
 {
 	int		i;

	//clean_memory()
	// this function should free all the memoryies used.
	// For that, this function has to take every structure allocated memory
 	i = -1;
	clear_exe(exe);
	delete_save_history(&g_h);
 	while (g_env[++i])
 		ft_strdel(&g_env[i]);
 	ft_strdel(&g_env[i]);
 	free(g_env);
	if (opt == CHILD_FAILURE)
		exit(-1);
	exit(0);
 }

void		ft_echo(t_exe *c)
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
