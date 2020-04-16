/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 23:35:55 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/15 23:51:05 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				possible_to_access_dir(t_exe *c)
{
	t_stat		sb;

	stat(c->av[1], &sb);
	if (access(c->av[1], F_OK))
	{
		error_monitor("cd: ", c->av[1], \
			": No such file or directory", NULL, EXIT_FAILURE, 0);
		return (0);
	}
	else if ((sb.st_mode & F_TYPE_MASK) != S_IFDIR)
	{
		error_monitor("cd: ", c->av[1], \
			": Not a directory", NULL, EXIT_FAILURE, 0);
		return (0);
	}
	else if (access(c->av[1], X_OK))
	{
		error_monitor("cd: ", c->av[1], \
			": Permission denied", NULL, EXIT_FAILURE, 0);
		return (0);
	}
	return (1);
}

int				possible_to_access_file(t_exe *c)
{
	if (c->av[0][0] == '.' || c->av[0][0] == '/')
	{
		if (access(c->av[0], F_OK))
		{
			error_monitor(c->av[0], ":No such file or dirrectory" \
			, NULL, NULL, EXIT_FAILURE, 0);
			return (0);
		}
		else if (access(c->av[0], X_OK))
		{
			error_monitor(c->av[0], ": Permission denied" \
			, NULL, NULL, EXIT_FAILURE, 0);
			return (0);
		}
		else
			return (1);
	}
	else
		return (0);
}
