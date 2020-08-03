/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:21:07 by ihwang            #+#    #+#             */
/*   Updated: 2020/08/02 19:01:52 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			post_signal(t_l *l)
{
	int tmp_pmpt;

	tmp_pmpt = l->pmpt;
	ft_putchar('\n');
	ft_strdel(&l->line);
	ft_memset(l, 0, sizeof(*l));
	l->pmpt = tmp_pmpt;
	l->x = l->pmpt;
	l->co = tgetnum("co");
	get_prompt();
	g_prompt = 0;
}

static	void	sig_int_handler(int sig)
{
	(void)sig;
	g_prompt = 1;
	ioctl(STDIN_FILENO, TIOCSTI, "");
}

static	void	sig_tstp_handler(int sig)
{
	(void)sig;
}

void			sig_controller(int option)
{
	if (option == PARENT)
	{
		signal(SIGINT, sig_int_handler);
		signal(SIGTSTP, sig_tstp_handler);
	}
	else if (option == CHILD)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
	}
}
