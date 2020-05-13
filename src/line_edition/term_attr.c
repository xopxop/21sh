/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:14:04 by ihwang            #+#    #+#             */
/*   Updated: 2020/05/11 15:31:05 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				restore_term(t_l *l)
{
	t_term			old;

	if (l->line == NULL)
		add_key("\n", l);
//	while ((l->y * l->co) + l->x - l->pmpt != l->nb)
//		ctrl_down(l);
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
}
