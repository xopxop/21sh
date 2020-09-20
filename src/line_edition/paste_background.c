/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 03:36:24 by marvin            #+#    #+#             */
/*   Updated: 2020/09/21 03:54:28 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void				paste_background(t_l *l, int clip_len)
{
	l->y += (l->x + clip_len) / l->co;
	l->x = (l->x + clip_len) % l->co;
	if (l->x == 0)
		 tputs(tgoto(tgetstr("cm", NULL), 0, \
		 			get_current_row() - 1), 1, ft_putchar);
	l->nb += clip_len;
}
