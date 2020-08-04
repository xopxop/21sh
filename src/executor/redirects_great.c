/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_great.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 01:52:52 by tango             #+#    #+#             */
/*   Updated: 2020/08/05 05:41:58 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			redirect_great(t_redirect *trav)
{
	int fd;

	if (!ft_strequ(trav->redirect_des, "-"))
	{
		fd = open(trav->redirect_des, O_WRONLY | O_TRUNC);
		dup2(fd, ft_atoi(trav->redirect_src));
	}
	else
		close(ft_atoi(trav->redirect_src));
}

void			redirect_dgreat(t_redirect *trav)
{
	int fd;

	if (!ft_strequ(trav->redirect_des, "-"))
	{
		fd = open(trav->redirect_des, O_WRONLY | O_APPEND);
		dup2(fd, ft_atoi(trav->redirect_src));
	}
	else
		close(ft_atoi(trav->redirect_src));
}

void			redirect_greatand(t_redirect *trav)
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
