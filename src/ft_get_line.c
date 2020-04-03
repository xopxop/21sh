/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 19:13:18 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/03 14:05:46 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				apply_termcap_str(char *str, int x, int y)
{
	if (!ft_strcmp(str, "ch"))
		ft_putstr_fd(tgoto(tgetstr(str, NULL), x, y), 0);
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


void				init_term(t_l *l)
{
	t_term			t;

	ft_memset(l, 0, sizeof(t_l));
	l->x = PMPT;
	tcgetattr(0, &t);
	default_term(&t);
	t.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t);
	if (!(tgetent(NULL, getenv("TERM"))))
	{
		ft_putstr_fd("Environment variable 'TERM' not set \n", 2);
		ft_exit(NULL, ER);
	}
	l->co = tgetnum("co");
}

static void			bs_key_str(t_l *l)
{
	int				i;

	if (l->y == 0)
	{
		ft_putstr(&l->line[l->x - PMPT]);
		i = l->x - 2 - PMPT;
		l->x--;
	}
	else
	{
		ft_putstr(&l->line[l->x + (l->co * l->y) - PMPT]);
		i = l->x + (l->co * l->y) - 2 - PMPT;
		if (l->x == 0)
		{
			l->x = l->co - 1;
			l->y--;
		}
		else
			l->x--;
	}
	while (++i < l->nb)
		l->line[i] = l->line[i + 1];
	l->nb--;
}

int					bs_key(t_l *l)
{
	if (l->y == 0 && l->x == PMPT)
		return (1);
	apply_termcap_str("#4", 0, 0);
	apply_termcap_str("cd", 0, 0);
	apply_termcap_str("sc", 0, 0);
	bs_key_str(l);
	apply_termcap_str("rc", 0, 0);
	return (1);
}

void				left_key(t_l *l)
{
	if (l->x == PMPT && l->y == 0)
		return ;
	if (l->x == 0 && l->y != 0)
	{
		l->y--;
		l->x = l->co - 1;
		apply_termcap_str("#4", 0, 0);
	}
	else
	{
		apply_termcap_str("#4", 0, 0);
		l->x--;
	}
}

void				right_key(t_l *l)
{
	if (l->x + (l->y * l->co) - PMPT == l->nb)
		return ;
	if (l->x != l->co - 1)
	{
		apply_termcap_str("nd", 0, 0);
		l->x++;
	}
	else
	{
		apply_termcap_str("do", 0, 0);
		l->x = 0;
		l->y++;
	}
}

int					parse_key(char t[], t_l *l)
{
	if (t[0] == 127 && t[1] == '\0')
		return (bs_key(l));
//	else if (t[0] == '\v' && t[1] == '\0')
//		return (ctrl_k());
//	else if (t[0] == 16 && t[1] == '\0')
//		return (ctrl_p());
	return (0);
}

void				append_char(char t[], t_l *l)
{
	char			*tmp;

	if (l->line == NULL)
		l->line = ft_strnew(2);
	tmp = ft_strjoin(l->line, t);
	ft_strdel(&l->line);
	l->line = tmp;
	l->nb++;
	if (l->x != l->co - 1)
		l->x++;
	else
	{
		l->x = 0;
		l->y++;
	}
	ft_putstr(&l->line[l->nb - 1]);
}

void				insert_char(char t[], t_l *l)
{
	char			*tmp;
//	int				x;

//	x = l->y == 0 ? l->x - PMPT : l->x;
	tmp = ft_strnew(l->nb + 1);
	tmp = ft_strncpy(tmp, l->line, l->x + (l->y * l->co) - PMPT);
	tmp = ft_addchar(tmp, t[0]);
	tmp = ft_strcat(tmp, &l->line[l->x + (l->y * l->co) - PMPT]);
	apply_termcap_str("im", 0, 0);
	ft_putchar(t[0]);
	ft_strdel(&l->line);
	l->line = tmp;
	l->nb++;
	if (l->x != l->co)
		l->x++;
	else
	{
		l->x = 0;
		l->y++;
	}
	apply_termcap_str("ei", 0, 0);
}

void				add_key(char t[], t_l *l)
{
	if (l->nb != l->x + (l->co * l->y) - PMPT)
		insert_char(t, l);
	else
		append_char(t, l);
}

void				parse_key_esc(char t[], t_l *l)
{
/*	if (t[0] == 27 && t[1] == 91 && t[2] == 'A')
		up_key();
	else if (t[0] == 27 && t[1] == 91 && t[2] == 'B')
		down_key();
		*/
	if (t[0] == 27 && t[1] == 91 && t[2] == 'D')
	//if (t[0] == 27)
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
	else if (ft_isprint(t[0])/* && t[0] != '['*/)
		add_key(t, l);
}

void				restore_term(t_l *l)
{
	t_term			old;

	if (l->line == NULL)
		add_key("\n", l);
	apply_termcap_str("do", 0, 0);
	old = default_term(NULL);
	tcsetattr(0, TCSANOW, &old);
}

void				ft_get_line(t_l *l)
{
	char			tmp[8];

	init_term(l);
	while (1)
	{
		ft_bzero(tmp, sizeof(tmp));
		read(0, tmp, sizeof(tmp));
		if (tmp[0] == '\n')
			return (restore_term(l));
		if (!parse_key(tmp, l))
			parse_key_esc(tmp, l);
	}
}
