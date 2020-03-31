/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:27:56 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/31 22:06:23 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		/*
		   'is_in_path' function checks if the given command(binary) is existing
		   in one of paths in 'PATH' env var. If so, 'is_in_path' returns
		   the path, otherwise 'NULL'.
		*/
		return (make_child_env(c, path));
		/*
		   'make_child_env' means that making child process(executing command)
		   that exists in 'PATH' env var
		*/
	if (there_is_p(c))
		/*
		   'there_is_p' checks if the given 'absolute path and file' exists
		   and if the path and file has proper permission
		*/
		make_child_not_env(c);
		/*
		   'make_child_not_env' means that making child process(executing command)
		   that does 'not' exist in 'PATH' env var
		*/
	else if (c->av[0][0] != '.' && c->av[0][0] != '/')
		print_no_cmd(c->av[0]);
}
