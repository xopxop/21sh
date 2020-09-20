/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:16:56 by ihwang            #+#    #+#             */
/*   Updated: 2020/08/06 16:45:35 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void				ctrl_up(t_l *l)
{
	if (l->y == 0)
	{
		apply_termcap_str("ch", 0, l->pmpt);
		l->x = l->pmpt;
	}
	else if (l->y == 1 && l->x < 3)
	{
		apply_termcap_str("up", 0, 0);
		apply_termcap_str("ch", 0, l->pmpt);
		l->y = 0;
		l->x = l->pmpt;
	}
	else
	{
		apply_termcap_str("up", 0, 0);
		l->y--;
	}
}

void				ctrl_down(t_l *l)
{
	if ((l->co * (l->y + 1)) + l->x > l->nb + l->pmpt)
	{
		if (l->co - l->x <= l->nb + l->pmpt - (l->x + (l->y * l->co)))
		{
			apply_termcap_str("do", 0, 0);
			l->y++;
		}
		apply_termcap_str("ch", 0, (l->nb + l->pmpt) - (l->y * l->co));
		l->x = (l->nb + l->pmpt) - (l->y * l->co);
	}
	else
	{
		apply_termcap_str("do", 0, 0);
		apply_termcap_str("ch", 0, l->x);
		l->y++;
	}
}
