/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:16:56 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/20 00:28:27 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ctrl_up(t_l *l)
{
	if (l->y == 0)
	{
		apply_termcap_str("ch", 0, PMPT);
		l->x = PMPT;
	}
	else if (l->y == 1 && l->x < 3)
	{
		apply_termcap_str("up", 0, 0);
		apply_termcap_str("ch", 0, PMPT);
		l->y = 0;
		l->x = PMPT;
	}
	else
	{
		apply_termcap_str("up", 0, 0);
		l->y--;
	}
}

void				ctrl_down(t_l *l)
{
	if ((l->co * (l->y + 1)) + l->x > l->nb + PMPT)
	{
		if (l->co - l->x < l->nb + PMPT - (l->x + (l->y * l->co)))
		{
			apply_termcap_str("do", 0, 0);
			l->y++;
		}
		apply_termcap_str("ch", 0, (l->nb + PMPT) - (l->y * l->co));
		l->x = (l->nb + PMPT) - (l->y * l->co);
	}
	else
	{
		apply_termcap_str("do", 0, 0);
		apply_termcap_str("ch", 0, l->x);
		l->y++;
	}
}
