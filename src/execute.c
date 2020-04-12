/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:27:56 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/12 20:05:28 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		is_builtin(char *comm)
{
	if (!ft_strcmp(comm, "exit") || !ft_strcmp(comm, "echo")
			|| !ft_strcmp(comm, "cd") || !ft_strcmp(comm, "env")
			|| !ft_strcmp(comm, "setenv") || !ft_strcmp(comm, "unsetenv")
			|| !ft_strcmp(comm, "pwd"))
		return (1);
	return (0);
}

static void		run_builtin(t_cmd *coms, t_h **h)
{
	if (!ft_strcmp(coms->av[0], "exit"))
		ft_exit(coms, PRINT, h);
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

void			execute_cmd(t_cmd *c, char *path, t_h **h)
{
	if (is_builtin(c->av[0]))
		return (run_builtin(c, h));
	else if ((path = is_in_path(c)))
		return (make_child_env(c, path, h));
	if (there_is_p(c))
		make_child_not_env(c, h);
	else if (c->av[0][0] != '.' && c->av[0][0] != '/')
		print_no_cmd(c->av[0]);
}
