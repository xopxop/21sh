/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:14:04 by ihwang            #+#    #+#             */
/*   Updated: 2020/08/06 18:17:47 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void				restore_term(t_l *l)
{
	t_term			old;

	if (l->line == NULL)
		add_key("\n", l);
	end_key(l);
	apply_termcap_str("do", 0, 0);
	old = get_set_default_term(NULL);
	tcsetattr(0, TCSANOW, &old);
}

t_term				get_set_default_term(t_term *t)
{
	static t_term	old;

	if (t)
		old = *t;
	return (old);
}

size_t				get_current_row(void)
{
	int				fd_tty;
	char			answer[16];
	size_t			answerlen;

	fd_tty = open("/dev/tty", O_RDWR);
	write(fd_tty, "\x1B[6n", 4);
	ft_memset(answer, 0, sizeof(answer));
	answerlen = 0;
	while ((read(fd_tty, answer + answerlen, 1)) == 1)
	{
		if (answer[answerlen++] == 'R')
			break ;
	}
	answer[answerlen] = '\0';
	close(fd_tty);
	return (ft_atoi(&answer[2]));
}

size_t				get_current_column(void)
{
	int				fd_tty;
	char			answer[16];
	size_t			answerlen;
	int				row;
	int				column;

	fd_tty = open("/dev/tty", O_RDWR);
	write(fd_tty, "\x1B[6n", 4);
	ft_memset(answer, 0, sizeof(answer));
	answerlen = 0;
	while ((read(fd_tty, answer + answerlen, 1)) == 1)
	{
		if (answer[answerlen++] == 'R')
			break ;
	}
	answer[answerlen] = '\0';
	close(fd_tty);
	row = ft_atoi(&answer[2]);
	if (ft_nbrlen(row) == 1)
		column = ft_atoi(&answer[4]);
	else
		column = ft_atoi(&answer[5]);
	return (column);
}

void				init_term(t_l *l)
{
	t_term			t;

	l->x = l->pmpt;
	tcgetattr(0, &t);
	get_set_default_term(&t);
	t.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t);
	if (!(tgetent(NULL, getenv("TERM"))))
	{
		ft_putstr_fd("Environment variable 'TERM' not set \n", 2);
		ft_exit(EXIT_FAILURE);
	}
	l->co = tgetnum("co");
	l->total_row = tgetnum("li");
	l->starting_row = l->total_row - get_current_row();
}
