/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_k.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:18:39 by ihwang            #+#    #+#             */
/*   Updated: 2020/08/05 05:42:47 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void			edit_line(t_l *l, int i, int j)
{
	char			*tmp;

	tmp = ft_strnew(l->nb - (j - i));
	tmp = ft_strncpy(tmp, l->line, i);
	tmp = ft_strcat(tmp, &l->line[j]);
	ft_strdel(&l->line);
	l->line = tmp;
}

static void			apply_to_screen(t_l *l, int i, int j, int y_dec)
{
	if (l->x < l->x + (l->y * l->co) - l->pmpt - i)
	{
		l->y -= y_dec;
		while (y_dec--)
			apply_termcap_str("up", 0, 0);
	}
	apply_termcap_str("ch", 0, (i + l->pmpt) % l->co);
	l->x = (i + l->pmpt) % l->co;
	apply_termcap_str("cd", 0, 0);
	apply_termcap_str("sc", 0, 0);
	ft_putstr(&l->line[i]);
	apply_termcap_str("rc", 0, 0);
	l->nb -= (j - i);
}

static void			clip_edit_apply(t_l *l, int i, int j, int y_dec)
{
	ctrl_k_clipping(l, i, j);
	edit_line(l, i, j);
	apply_to_screen(l, i, j, y_dec);
}

int					ctrl_k(t_l *l, int y_dec)
{
	int				curr;
	int				i;
	int				j;

	i = l->x + (l->y * l->co) - l->pmpt;
	curr = i;
	while (i >= 0)
	{
		if (!l->line)
			return (1);
		if ((ft_iswhite(l->line[i ? i - 1 : 0]) && !ft_iswhite(l->line[i]) &&
		!ft_iswhite(l->line[curr])) || (i == 0 && !ft_iswhite(l->line[curr])))
		{
			j = i - 1;
			while (++j < l->nb)
				if (ft_iswhite(l->line[j]))
					break ;
			clip_edit_apply(l, i, j, y_dec);
			break ;
		}
		(i + l->pmpt) % l->co == 0 ? y_dec++ : 0;
		i--;
	}
	return (1);
}
