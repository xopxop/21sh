/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_end_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:10:13 by ihwang            #+#    #+#             */
/*   Updated: 2020/08/05 05:43:07 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int					home_key(t_l *l)
{
	int				i;

	i = l->y;
	while (i--)
		apply_termcap_str("up", 0, 0);
	apply_termcap_str("ch", 0, l->pmpt);
	l->x = l->pmpt;
	l->y = 0;
	return (1);
}

int					end_key(t_l *l)
{
	int				i;

	home_key(l);
	l->y = (l->nb + l->pmpt) / l->co;
	l->x = (l->nb + l->pmpt) % l->co;
	i = l->y;
	while (i--)
		apply_termcap_str("do", 0, 0);
	apply_termcap_str("ch", 0, l->x);
	return (1);
}
