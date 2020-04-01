/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 19:13:18 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/01 14:42:03 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh.h"

t_term				default_term(t_term *t)
{
	static t_term	old;

	if (t)
	{
		old = *t;
		return (0);
	}
	else
		return (old);
}

void				init_term(void)
{
	t_term			t;

	tcgetattr(0, &t);
	default_term(t);
	t.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &t);
}


int					bs_key(t_l *l)
{
	int				i;

	if (l->curr == 0)
		return (0);
	i = l->curr--;
	ft_putstr(tgetstr("#4", NULL), 0);
	ft_putstr(tgetstr("cd", NULL), 0);
	ft_putstr(l->line[0][i]);
	i -= 2;
	while (++i < l->nb)
		l->line[0][i] = l->line[0][i + 1];
	l->nb--;
}

void				left_key(t_l *l)
{
	if (l->curr == 0)
		return ;
	ft_putstr(tgetstr("#4", NULL), 0);
	l->curr--;
}

void				right_key(t_l *l)
{
	if (l->curr == l->nb)
		return ;
	ft_putstr(tgetstr("%i", NULL), 0);
	l->curr++;
}

int					parse_key(char t[], t_l *l)
{
	if (t[0] == 127 && t[1] == '\0')
		return (bs_key(l));
	else if (t[0] == '\n' && t[1] == '\0')
		return (enter_key());
	else if (t[0] == '\v' && t[1] == '\0')
		return (ctrl_k());
	else if (t[0] == 16 && t[1] == '\0')
		return (ctrl_p());
	return (1);
}
void				
void				add_key(char t[], t_l *l)
{
	if (!ft_isprint(t[0]))
		return ;
	if (l->nb != l->curr)
	{

	


}

void				parse_key_esc(char t[], t_l *l)
{
	if (t[0] == 27 && t[1] == 91 && t[2] == 'A')
		up_key();
	else if (t[0] == 27 && t[1] == 91 && t[2] == 'B')
		down_key();
	else if (t[0] == 27 && t[1] == 91 && t[2] == 'D')
		left_key(l);
	else if (t[0] == 27 && t[1] == 91 && t[2] == 'C')
		right_key(l);
	else if (!ft_strcmp(&tmp[1], "[1;5A"))
		ctrl_up();
	else if (!ft_strcmp(&tmp[1], "[1;5B"))
		ctrl_down();
	else if (!ft_strcmp(&tmp[1], "[1;5C"))
		ctrl_right();
	else if (!ft_strcmp(&tmp[1], "[1;5D"))
		ctrl_left();
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
