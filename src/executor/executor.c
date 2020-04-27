/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 08:06:41 by dthan             #+#    #+#             */
/*   Updated: 2020/04/27 13:32:44 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int		is_builtin(char *comm)
{
	if (!ft_strcmp(comm, "exit") || !ft_strcmp(comm, "echo")
			|| !ft_strcmp(comm, "cd") || !ft_strcmp(comm, "env")
			|| !ft_strcmp(comm, "setenv") || !ft_strcmp(comm, "unsetenv")
			|| !ft_strcmp(comm, "pwd"))
		return (1);
	return (0);
}

static void		run_builtin(t_exe *coms)
{
	if (!ft_strcmp(coms->av[0], "exit"))
	 	ft_exit(coms, NORM); // Not done. need more 'free'
	if (!ft_strcmp(coms->av[0], "pwd"))
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

void run (t_exe *c)
{
	char *path;

	path = NULL;
	if (is_builtin(c->av[0]))
		return (run_builtin(c));
	else if ((path = is_in_path(c)))
	 	return (make_child_path(c, path));
	if (possible_to_access_file(c))
		make_child_binary(c);
	else if (c->av[0][0] != '.' && c->av[0][0] != '/')
		error_monitor(c->av[0], ": command not found", \
		NULL, NULL, EXIT_FAILURE, 0);
}

void executor(t_astnode *ast)
{
	t_exe exec;

	printBinaryTree(ast);
	ft_bzero(&exec, sizeof(t_exe));
	execute_complete_command(ast, &exec);
}
