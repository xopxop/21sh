/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 08:06:41 by dthan             #+#    #+#             */
/*   Updated: 2020/08/01 22:22:17 by ihwang           ###   ########.fr       */
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
	 	ft_exit(EXIT_SUCCESS); // Not done. need more 'free'
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

void redirect_great(t_redirect *trav)
{
	int fd;

	if (!ft_strequ(trav->redirect_des, "-"))
	{
		fd = open(trav->redirect_des, O_WRONLY | O_TRUNC);
		// need to handle error
		dup2(fd, ft_atoi(trav->redirect_src));
	}
	else
		close(ft_atoi(trav->redirect_src));
}

void redirect_dgreat(t_redirect *trav)
{
	int fd;

	if (!ft_strequ(trav->redirect_des, "-"))
	{
		fd = open(trav->redirect_des, O_WRONLY | O_APPEND);
		// need to handle error
		dup2(fd, ft_atoi(trav->redirect_src));
	}
	else
		close(ft_atoi(trav->redirect_src));
}



void redirect_greatand(t_redirect *trav)
{
	int fd;

	if (!is_made_of_digits(trav->redirect_des) && \
		!ft_strequ("-", trav->redirect_des))
	{
		fd = open(trav->redirect_des, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dup2(fd, ft_atoi(trav->redirect_src));
	}
	else if (is_made_of_digits(trav->redirect_des))
		dup2(ft_atoi(trav->redirect_des), ft_atoi(trav->redirect_src));
	else
		close(ft_atoi(trav->redirect_src));
}

void redirect_lessand(t_redirect *trav)
{
	t_stat sb;
	int fd;

	fd = ft_atoi(trav->redirect_src);
	if (!is_made_of_digits(trav->redirect_src) && !ft_strequ(trav->redirect_src, "-"))
	{
		error_monitor(SYNTAX_AMBIG_REDI, trav->redirect_src, NULL, NULL, 1, 0);
		ft_exit(EXIT_FAILURE);
	}
	else if (ft_strequ(trav->redirect_src, "-"))
		close(ft_atoi(trav->redirect_des));
	else if ((fstat(fd, &sb)) < 0)
	{
		error_monitor(SYNTAX_BAD_FD, trav->redirect_src, NULL, NULL, 1, 0);
		ft_exit(EXIT_FAILURE);
	}
	else if (!(sb.st_mode & S_IRUSR))
	{
		error_monitor(SYNTAX_BAD_FD, trav->redirect_src, NULL, NULL, 1, 0);
		ft_exit(EXIT_FAILURE);
	}
	else
		dup2(fd, ft_atoi(trav->redirect_des));
}

void redirect_less(t_redirect *trav)
{
	int fd;

	fd = open(trav->redirect_src, O_RDONLY);
	if (fd == -1)
		error_monitor(SHELL_ENOENT, trav->redirect_src, NULL, \
			NULL, 0, EXIT_FAILURE);
	dup2(fd, ft_atoi(trav->redirect_des));
}

void redirect_dless(t_exe *exe)
{
	int fd[2];

	pipe(fd);
	ft_putstr_fd(exe->heredoc->heredoc, fd[WRITE_END]);
	close(fd[WRITE_END]);
	dup2(fd[READ_END], STDIN_FILENO);
}

void handle_redirect(t_exe exe)
{
	t_redirect *traverse;

	traverse = exe.redi;
	while (traverse)
	{
		if (ft_strequ(traverse->redirect_op, ">"))
			redirect_great(traverse);
		else if (ft_strequ(traverse->redirect_op, ">>"))
			redirect_dgreat(traverse);
		else if (ft_strequ(traverse->redirect_op, "<"))
			redirect_less(traverse);
		else if (ft_strequ(traverse->redirect_op, "<<"))
			redirect_dless(&exe);
		else if (ft_strequ(traverse->redirect_op, ">&"))
			redirect_greatand(traverse);
		else if (ft_strequ(traverse->redirect_op, "<&"))
			redirect_lessand(traverse);
		traverse = traverse->next;
	}
}

void run (t_exe *c)
{
	char *path;
	pid_t pid;

	path = NULL;
	if (is_builtin(c->av[0]))
		return (run_builtin(c));
	if ((pid = fork()) == 0)
	{
		if (c->redi != NULL)
			handle_redirect(*c);
		if (!ft_strcmp(c->av[0], "echo"))
		{
		 	ft_echo(c);
			ft_exit(EXIT_SUCCESS);
		}
		if ((path = is_in_path(c)))
	 		return (make_child_path(c, path));
		if (possible_to_access_file(c))
			make_child_binary(c);
		else if (c->av[0][0] != '.' && c->av[0][0] != '/')
			error_monitor(c->av[0], ": command not found", \
			NULL, NULL, EXIT_FAILURE, 0);
		ft_exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, NULL, 0);
		//wait(NULL);
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
	clear_ast(ast);
	clear_exe(&exec);
}