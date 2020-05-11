/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_k_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:18:39 by ihwang            #+#    #+#             */
/*   Updated: 2020/05/10 23:43:39 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ctrl_k_edit_line(t_l *l, int i, int j)
{
	char			*tmp;

	tmp = ft_strnew(l->nb - (j - i));
	tmp = ft_strncpy(tmp, l->line, i);
	tmp = ft_strcat(tmp, &l->line[j]);
	ft_strdel(&l->line);
	l->line = tmp;
}

static void			ctrl_k_apply_to_screen(t_l *l, int i, int j, int y_dec)
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

static void			ctrl_p_apply_screen(t_l *l, char *clip, int i)
{
	apply_termcap_str("cd", 0, 0);
	ft_putstr(clip);
	apply_termcap_str("sc", 0, 0);
	if (l->line)
		ft_putstr(&l->line[i]);
	apply_termcap_str("rc", 0, 0);
}

int					ctrl_p(t_l *l, int clip_len, int i)
{
	char			*clip;
	char			*tmp;

	if (!(clip = clipboard(NULL, CLIP_TAKE)))
		return (1);
	clip_len = ft_strlen(clip);
	i = l->x + (l->y * l->co) - l->pmpt;
	ctrl_p_apply_screen(l, clip, i);
	tmp = ft_strnew(l->nb + clip_len);
	if (l->line)
		tmp = ft_strncpy(tmp, l->line, i);
	tmp = ft_strcat(tmp, clip);
	if (l->line)
		tmp = ft_strcat(tmp, &l->line[i]);
	ft_strdel(&l->line);
	l->line = tmp;
	if (l->x + clip_len > l->co - 1)
	{
		l->y += (l->x + clip_len) / l->co;
		l->x = (l->x + clip_len) % l->co;
	}
	else
		l->x += clip_len;
	l->nb += clip_len;
	return (1);
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
		if ((ft_iswhite(l->line[i - 1]) && !ft_iswhite(l->line[i]) &&
		!ft_iswhite(l->line[curr])) || (i == 0 && !ft_iswhite(l->line[curr])))
		{
			j = i - 1;
			while (++j < l->nb)
				if (ft_iswhite(l->line[j]))
					break ;
			ctrl_k_clipping(l, i, j);
			ctrl_k_edit_line(l, i, j);
			ctrl_k_apply_to_screen(l, i, j, y_dec);
			break ;
		}
		(i + l->pmpt) % l->co == 0 ? y_dec++ : 0;
		i--;
	}
	return (1);
}
