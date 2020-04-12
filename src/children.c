/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:14:05 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/12 20:05:02 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		make_child_not_env(t_cmd *c, t_h **h)
{
	pid_t	pid;
	t_stat	sb;
	char	buf[PATH_MAX];

	lstat(c->av[0], &sb);
	if ((sb.st_mode & F_TYPE_MASK) != S_IFREG)
		return (print_is_dir(c->av[0]));
	ft_strcpy(buf, c->av[0]);
	pid = fork();
	if (pid == 0)
	{
		sig_controller(CHILD);
		execve(buf, c->av, g_env);
		ft_exit(c, ER, h);
	}
	else
		waitpid(pid, &g_status, 0);
}

static void	make_child_env_sub(t_cmd *c, char buf[], t_h **h)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		sig_controller(CHILD);
		execve(buf, c->av, g_env);
		ft_exit(c, ER, h);
	}
	else
		waitpid(pid, &g_status, 0);
}

void		make_child_env(t_cmd *c, char *path, t_h **h)
{
	char	buf[PATH_MAX];

	ft_strcpy(buf, path);
	ft_strdel(&path);
	if (access(buf, X_OK))
	{
		ft_putstr_fd(buf, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return ;
	}
	ft_strcat(buf, "/");
	ft_strcat(buf, c->av[0]);
	if (!access(buf, X_OK))
		make_child_env_sub(c, buf, h);
	else
	{
		ft_putstr_fd(buf, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
}
