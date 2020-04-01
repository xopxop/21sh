/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 19:13:18 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/02 00:56:52 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				apply_termcap_str(char *str, int x, int y)
{
	if (x && y)
		NULL;
	else if (y)
		ft_putstr_fd(tgoto(tgetstr(str, NULL), 0, y), 0);
	else
		ft_putstr_fd(tgetstr(str, NULL), 0);
}

t_term				default_term(t_term *t)
{
	static t_term	old;

	if (t)
		old = *t;
	return (old);
}

void				init_term(void)
{
	t_term			t;

	tcgetattr(0, &t);
	default_term(&t);
	t.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t);
	if (!(tgetent(NULL, getenv("TERM"))))
	{
		ft_putstr_fd("Environment variable 'TERM' not set \n", 2);
		ft_exit(NULL, ER);
	}
}

/*
int					bs_key(t_l *l)
{
	int				i;

	if (l->curr == 0)
		return (0);
	i = l->curr--;
	ft_putstr_fd(tgetstr("#4", NULL), 0);
	ft_putstr_fd(tgetstr("cd", NULL), 0);
	ft_putstr(&l->line[i]);
	i -= 2;
	while (++i < l->nb)
		l->line[i] = l->line[i + 1];
	l->nb--;
}
*/

void				left_key(t_l *l)
{
	if (l->curr == 0)
		return ;
	apply_termcap_str("#4", 0, 0);
	l->curr--;
}

void				right_key(t_l *l)
{
	if (l->curr == l->nb)
		return ;
	apply_termcap_str("nd", 0, 0);
	l->curr++;
}

int					parse_key(char t[], t_l *l)
{
	if (t[0] == 127 && t[1] == '\0')
		return (bs_key(l));
//	else if (t[0] == '\n' && t[1] == '\0')
//		return (enter_key());
//	else if (t[0] == '\v' && t[1] == '\0')
//		return (ctrl_k());
//	else if (t[0] == 16 && t[1] == '\0')
//		return (ctrl_p());
	return (1);
}

void				add_char(char t[], t_l *l, int opt)
{
	char			*tmp;

	if (l->line == NULL)
		l->line = ft_strnew(2);
	if (opt == APPEND)
		tmp = ft_strjoin(l->line, t);
	else
	{
		tmp = ft_strnew(l->nb + 2);
		tmp = ft_strncpy(tmp, l->line, l->curr);
		tmp = ft_addchar(tmp, t[0]);
		tmp = ft_strcat(tmp, &l->line[l->curr]);
		ft_putstr(&l->line[l->curr]);
	}
	ft_strdel(&l->line);
	l->line = tmp;
	l->nb++;
	l->curr++;
	ft_putstr(&l->line[l->nb - 1]);
}

void				add_key(char t[], t_l *l)
{
	if (l->nb != l->curr)
		add_char(t, l, INSERT);
	else
		add_char(t, l, APPEND);
}

void				parse_key_esc(char t[], t_l *l)
{
/*	if (t[0] == 27 && t[1] == 91 && t[2] == 'A')
		up_key();
	else if (t[0] == 27 && t[1] == 91 && t[2] == 'B')
		down_key();
		*/
	if (t[0] == 27 && t[1] == 91 && t[2] == 'D')
		left_key(l);
	else if (t[0] == 27 && t[1] == 91 && t[2] == 'C')
		right_key(l);
/*	else if (!ft_strcmp(&tmp[1], "[1;5A"))
		ctrl_up();
	else if (!ft_strcmp(&tmp[1], "[1;5B"))
		ctrl_down();
	else if (!ft_strcmp(&tmp[1], "[1;5C"))
		ctrl_right();
	else if (!ft_strcmp(&tmp[1], "[1;5D"))
		ctrl_left();
		*/
	else if (ft_isprint(t[0]))
		add_key(t, l);
}

void				ft_get_line(t_l *l)
{
	char	tmp[8];

	init_term();
	while (1)
	{
		ft_bzero(tmp, sizeof(tmp));
		read(0, tmp, sizeof(tmp));
		if (!parse_key(tmp, l))
			parse_key_esc(tmp, l);
	}


}
