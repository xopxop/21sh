/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_end_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:10:13 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/20 00:28:31 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					home_key(t_l *l)
{
	int				i;

	i = l->y;
	while (i--)
		apply_termcap_str("up", 0, 0);
	apply_termcap_str("ch", 0, PMPT);
	l->x = PMPT;
	l->y = 0;
	return (1);
}

int					end_key(t_l *l)
{
	int				i;

	home_key(l);
	l->y = (l->nb + PMPT) / l->co;
	l->x = (l->nb + PMPT) % l->co;
	i = l->y;
	while (i--)
		apply_termcap_str("do", 0, 0);
	apply_termcap_str("ch", 0, l->x);
	return (1);
}
