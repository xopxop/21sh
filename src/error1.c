/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:48:26 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/28 19:03:07 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh.h"

void			print_is_dir(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": is a directory\n", 2);
}

void			print_no_cmd(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void			print_set_unset(char *str, int opt)
{
	if (opt == SET)
		ft_putstr_fd("setenv: '", 2);
	else if (opt == UNSET)
		ft_putstr_fd("unsetenv: '", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid indentifier\n", 2);
}

int				there_is_d(t_cmd *c)
{
	t_stat		sb;

	stat(c->av[1], &sb);
	if (access(c->av[1], F_OK))
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(c->av[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (0);
	}
	else if ((sb.st_mode & F_TYPE_MASK) != S_IFDIR)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(c->av[1], 2);
		ft_putstr_fd(": Not a directory\n", 2);
		return (0);
	}
	else if (access(c->av[1], X_OK))
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(c->av[1], 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (0);
	}
	return (1);
}

int				there_is_p(t_cmd *c)
{
	if (c->av[0][0] == '.' || c->av[0][0] == '/')
	{
		if (access(c->av[0], F_OK))
		{
			ft_putstr_fd(c->av[0], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return (0);
		}
		else if (access(c->av[0], X_OK))
		{
			ft_putstr_fd(c->av[0], 2);
			ft_putstr_fd(": Permission denied\n", 2);
			return (0);
		}
		else
			return (1);
	}
	else
		return (0);
}
