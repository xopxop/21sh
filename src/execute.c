/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:27:56 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/28 19:03:11 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh.h"

static int		is_builtin(char *comm)
{
	if (!ft_strcmp(comm, "exit") || !ft_strcmp(comm, "echo")
			|| !ft_strcmp(comm, "cd") || !ft_strcmp(comm, "env")
			|| !ft_strcmp(comm, "setenv") || !ft_strcmp(comm, "unsetenv")
			|| !ft_strcmp(comm, "pwd"))
		return (1);
	return (0);
}

static void		run_builtin(t_cmd *coms)
{
	if (!ft_strcmp(coms->av[0], "exit"))
		ft_exit(coms, PRINT);
	else if (!ft_strcmp(coms->av[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(coms->av[0], "cd"))
		ft_cd(coms);
	else if (!ft_strcmp(coms->av[0], "env"))
		ft_env();
	else if (!ft_strcmp(coms->av[0], "echo"))
		ft_echo(coms);
	else if (!ft_strcmp(coms->av[0], "setenv"))
		ft_setenv(coms);
	else if (!ft_strcmp(coms->av[0], "unsetenv"))
		ft_unsetenv(coms);
}

void			execute_cmd(t_cmd *c, char *path)
{
	if (is_builtin(c->av[0]))
		return (run_builtin(c));
	else if ((path = is_in_path(c)))
		return (make_child_env(c, path));
	if (there_is_p(c))
		make_child_not_env(c);
	else if (c->av[0][0] != '.' && c->av[0][0] != '/')
		print_no_cmd(c->av[0]);
}
