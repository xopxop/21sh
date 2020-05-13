/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:21:14 by ihwang            #+#    #+#             */
/*   Updated: 2020/05/10 23:44:14 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			up_down_key_apply_statuses(t_l *l)
{
	int				i;

	i = l->y;
	while (i--)
		apply_termcap_str("up", 0, 0);
	apply_termcap_str("ch", 0, l->pmpt);
	apply_termcap_str("cd", 0, 0);
	l->nb = ft_strlen(l->line);
	l->y = (l->nb + l->pmpt) / l->co;
	l->x = (l->nb + l->pmpt) % l->co;
	ft_putstr(l->line);
}

static void			up_key(t_l *l, t_h **h)
{
	t_h				*trav;
	int				i;

	if (!*h || l->curr == h[0]->nb)
		return ;
	trav = *h;
	i = l->curr - 1;
	l->curr++;
	while (i-- > -1)
		trav = trav->next;
	ft_strdel(&l->line);
	l->line = ft_strdup(trav->data);
	up_down_key_apply_statuses(l);
}

static void			down_key(t_l *l, t_h **h, char *first)
{
	t_h				*trav;
	int				i;

	if (!*h || l->curr == 0)
		return ;
	trav = *h;
	l->curr--;
	i = l->curr - 1;
	ft_strdel(&l->line);
	if (l->curr)
	{
		while (i--)
			trav = trav->next;
		l->line = ft_strdup(trav->data);
	}
	else if (first)
		l->line = ft_strdup(first);
	else
		l->line = ft_strnew(0);
	up_down_key_apply_statuses(l);
}

void				up_down(t_l *l, t_h **h, char t[])
{
	static char		*tmp;

	if (t == NULL)
		ft_strdel(&tmp);
	else if (t[0] == 27 && t[1] == 91 && t[2] == 'A')
	{
		if (l->curr == 0 && l->line && ft_isprint(l->line[0]))
			tmp = ft_strdup(l->line);
		up_key(l, h);
	}
	else if (t[0] == 27 && t[1] == 91 && t[2] == 'B')
		down_key(l, h, tmp);
}
