/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_less.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 01:52:52 by tango             #+#    #+#             */
/*   Updated: 2020/08/05 05:41:59 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		redirect_lessand(t_redirect *trav)
{
	t_stat	sb;
	int		fd;

	fd = ft_atoi(trav->redirect_src);
	if (!is_made_of_digits(trav->redirect_src) && \
			!ft_strequ(trav->redirect_src, "-"))
	{
		error_monitor(SYNTAX_AMBIG_REDI, trav->redirect_src, NULL, 1);
		ft_exit(EXIT_FAILURE);
	}
	else if (ft_strequ(trav->redirect_src, "-"))
		close(ft_atoi(trav->redirect_des));
	else if ((fstat(fd, &sb)) < 0)
	{
		error_monitor(SYNTAX_BAD_FD, trav->redirect_src, NULL, 1);
		ft_exit(EXIT_FAILURE);
	}
	else if (!(sb.st_mode & S_IRUSR))
	{
		error_monitor(SYNTAX_BAD_FD, trav->redirect_src, NULL, 1);
		ft_exit(EXIT_FAILURE);
	}
	else
		dup2(fd, ft_atoi(trav->redirect_des));
}

void		redirect_less(t_redirect *trav)
{
	int fd;

	fd = open(trav->redirect_src, O_RDONLY);
	if (fd == -1)
		error_monitor(SHELL_ENOENT, trav->redirect_src, NULL, 0);
	dup2(fd, ft_atoi(trav->redirect_des));
}

void		redirect_dless(t_exe *exe)
{
	int fd[2];

	pipe(fd);
	ft_putstr_fd(exe->heredoc->heredoc, fd[WRITE_END]);
	close(fd[WRITE_END]);
	dup2(fd[READ_END], STDIN_FILENO);
}
