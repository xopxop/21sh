/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_left_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:15:39 by ihwang            #+#    #+#             */
/*   Updated: 2020/08/05 05:42:50 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void				ctrl_right(t_l *l)
{
	int				i;
	int				y_inc;

	y_inc = 0;
	i = l->x + (l->y * l->co) - l->pmpt;
	if (ft_iswhite(l->line[i ? i - 1 : 0]) && !ft_iswhite(l->line[i]) && i)
		i++;
	while (i <= l->nb)
	{
		if ((ft_iswhite(l->line[i ? i - 1 : 0]) && !ft_iswhite(l->line[i]) && i)
				|| i == l->nb)
		{
			if (i + l->pmpt - (l->x + (l->y * l->co)) >= l->co - l->x)
			{
				l->y += y_inc;
				while (y_inc--)
					apply_termcap_str("do", 0, 0);
			}
			apply_termcap_str("ch", 0, (i + l->pmpt) % l->co);
			l->x = (i + l->pmpt) % l->co;
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

void				ctrl_left(t_l *l, int y_dec)
{
	int				i;
	int				curr;

	i = l->x + (l->y * l->co) - l->pmpt;
	curr = i;
	ft_iswhite(l->line[i - 1]) && !ft_iswhite(l->line[i]) && i ? i-- : 0;
	while (i >= 0)
	{
		if (i == 0)
			ctrl_left_for_zero(l, y_dec);
		else if (ft_iswhite(l->line[i - 1]) && !ft_iswhite(l->line[i]))
		{
			if (l->x < curr - i)
			{
				l->y -= y_dec;
				while (y_dec--)
					apply_termcap_str("up", 0, 0);
			}
			apply_termcap_str("ch", 0, (i + l->pmpt) % l->co);
			l->x = (i + l->pmpt) % l->co;
			break ;
		}
		(i + l->pmpt) % l->co == 0 ? y_dec++ : 0;
		i--;
	}
}
