/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 08:06:41 by dthan             #+#    #+#             */
/*   Updated: 2020/05/05 01:55:45 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int		is_builtin(char *comm)
{
	if (!ft_strcmp(comm, "exit") || !ft_strcmp(comm, "cd") || \
		!ft_strcmp(comm, "env") || !ft_strcmp(comm, "setenv") || \
		!ft_strcmp(comm, "unsetenv") || !ft_strcmp(comm, "pwd"))
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
	else if (!ft_strcmp(coms->av[0], "setenv"))
	 	ft_setenv(coms);
	else if (!ft_strcmp(coms->av[0], "unsetenv"))
	 	ft_unsetenv(coms);
}

void redirect_great(t_exe exe, int nb)
{
	int fd;

	if (!ft_strequ(exe.redirect_des[nb], "-"))
	{
		fd = open(exe.redirect_des[nb], O_WRONLY | O_TRUNC);
		// need to handle error
		dup2(fd, ft_atoi(exe.redirect_src[nb]));
	}
	else
		close(ft_atoi(exe.redirect_src[nb]));
}

void redirect_dgreat(t_exe exe, int nb)
{
	int fd;

	if (!ft_strequ(exe.redirect_des[nb], "-"))
	{
		fd = open(exe.redirect_des[nb], O_WRONLY | O_APPEND);
		// need to handle error
		dup2(fd, ft_atoi(exe.redirect_src[nb]));
	}
	else
		close(ft_atoi(exe.redirect_src[nb]));
}

void redirect_less(t_exe exe, int nb)
{
	int fd;

	fd = open(exe.redirect_src[nb], O_RDONLY);
	if (fd == -1)
		error_monitor(SHELL_ENOENT, exe.redirect_src[nb], NULL, \
			NULL, 0, EXIT_FAILURE);
	dup2(fd, STDIN_FILENO);
}

void redirect_greatand(t_exe exe, int nb)
{
	int fd;

	if (!is_made_of_digits(exe.redirect_des[nb]) && \
		!ft_strequ("-", exe.redirect_des[nb]))
	{
		fd = open(exe.redirect_des[nb], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dup2(fd, ft_atoi(exe.redirect_src[nb]));
	}
	else if (is_made_of_digits(exe.redirect_des[nb]))
		dup2(ft_atoi(exe.redirect_des[nb]), ft_atoi(exe.redirect_src[nb]));
	else
		close(ft_atoi(exe.redirect_src[nb]));
}

void redirect_dless(t_exe *exe)
{
	int fd[2];
	t_heredoc *temp;

	pipe(fd);
	ft_putstr_fd(exe->heredoc->heredoc, fd[WRITE_END]);
	temp = exe->heredoc;
	exe->heredoc = exe->heredoc->next;
	ft_strdel(&temp->heredoc);
	free(temp);
	close(fd[WRITE_END]);
	dup2(fd[READ_END], STDIN_FILENO);
}

void handle_redirect(t_exe exe)
{
	int nb;

	nb = -1;
	while (++nb < REDI_MAX && exe.redirect_op[nb])
	{
		if (ft_strequ(exe.redirect_op[nb], ">"))
			redirect_great(exe, nb);
		else if (ft_strequ(exe.redirect_op[nb], ">>"))
			redirect_dgreat(exe, nb);
		else if (ft_strequ(exe.redirect_op[nb], "<"))
			redirect_less(exe, nb);
		else if (ft_strequ(exe.redirect_op[nb], "<<"))
			redirect_dless(&exe);
		else if (ft_strequ(exe.redirect_op[nb], ">&"))
			redirect_greatand(exe, nb);
	}
}

void run (t_exe *c)
{
	char *path;

	path = NULL;
	if (is_builtin(c->av[0]))
		return (run_builtin(c));
	if (fork() == 0)
	{
		if (c->redirect_op != NULL)
			handle_redirect(*c);
		if (!ft_strcmp(c->av[0], "echo"))
		{
		 	ft_echo(c);
			exit(EXIT_SUCCESS);
		}
		if ((path = is_in_path(c)))
	 		return (make_child_path(c, path));
		if (possible_to_access_file(c))
			make_child_binary(c);
		else if (c->av[0][0] != '.' && c->av[0][0] != '/')
			error_monitor(c->av[0], ": command not found", \
			NULL, NULL, EXIT_FAILURE, 0);
		ft_exit(c, NORM);
	}
	else
		wait(NULL);
}

/*
** Note form dthan for future de-allocating memory
** In this t_exe allocate:
** 		+ allocating maximum argument size an array of a pointer type char
**		+ A linked list of heredoc in case there is heredoc
*/

void executor(t_astnode *ast)
{
	t_exe exec;

	printBinaryTree(ast);
	ft_bzero(&exec, sizeof(t_exe));
	exec.av = (char**)malloc(sysconf(_SC_ARG_MAX));
	find_heredoc(ast, &exec);
	execute_complete_command(ast, &exec);
}