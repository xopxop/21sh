/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_left_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:15:39 by ihwang            #+#    #+#             */
/*   Updated: 2020/08/06 05:02:21 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void			move_cursor_right(t_l *l, int y_inc, int i)
{
	if (i + l->pmpt - (l->x + (l->y * l->co)) >= l->co - l->x)
	{
		l->y += y_inc;
		while (y_inc--)
			apply_termcap_str("do", 0, 0);
	}
	apply_termcap_str("ch", 0, (i + l->pmpt) % l->co);
	l->x = (i + l->pmpt) % l->co;
}

void				ctrl_right(t_l *l)
{
	int				i;
	int				y_inc;
	char			*curr_pos;

	y_inc = 0;
	i = l->x + (l->y * l->co) - l->pmpt;
	curr_pos = &l->line[i];
	while (i <= l->nb)
	{
		if ((ft_iswhite(l->line[i ? i - 1 : 0]) && !ft_iswhite(l->line[i])
			&& i && curr_pos != &l->line[i])
				|| i == l->nb)
		{
			move_cursor_right(l, y_inc, i);
			break ;
		}
		((i + l->pmpt) % l->co == l->co - 1) ? y_inc++ : 0;
		i++;
	}
}

static void			ctrl_left_for_zero(t_l *l, int y_dec)
{
	l->x = l->pmpt;
	l->y = 0;
	while (y_dec--)
		apply_termcap_str("up", 0, 0);
	apply_termcap_str("ch", 0, l->pmpt);
}

static void			move_cursor_left(t_l *l, int y_dec, int i, int curr)
{
	if (l->x < curr - i)
	{
		l->y -= y_dec;
		while (y_dec--)
			apply_termcap_str("up", 0, 0);
	}
	apply_termcap_str("ch", 0, (i + l->pmpt) % l->co);
	l->x = (i + l->pmpt) % l->co;
}

void				ctrl_left(t_l *l, int y_dec)
{
	int				i;
	int				curr;
	char			*curr_address;

	if (!l->line)
		return ;
	i = l->x + (l->y * l->co) - l->pmpt;
	curr = i;
	curr_address = &l->line[i];
	while (i >= 0)
	{
		if (i == 0)
			ctrl_left_for_zero(l, y_dec);
		else if (ft_iswhite(l->line[i - 1]) && !ft_iswhite(l->line[i])
			&& &l->line[i] != curr_address)
		{
			move_cursor_left(l, y_dec, i, curr);
			break ;
		}
		if ((i + l->pmpt) % l->co == 0)
			y_dec++;
		i--;
	}
}
