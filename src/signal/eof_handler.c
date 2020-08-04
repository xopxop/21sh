/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:09:25 by tango             #+#    #+#             */
/*   Updated: 2020/08/05 05:45:31 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			iseof_in_line(char *line)
{
	while (*line)
	{
		if (*line == '\x04')
			return (1);
		++line;
	}
	return (0);
}

void		eof_handler(t_l *l)
{
	char	*tmp;
	t_term	old;

	if (l->type == LINE_TYPE_SINGLE)
	{
		restore_term(l);
		ft_exit(EXIT_SUCCESS);
	}
	else if (l->type == LINE_TYPE_DQUOTE)
	{
		error_monitor("\n21sh: unexpected EOF while looking",
				" for matchin `\"\'", NULL, 0);
		tmp = ft_strjoin(l->line, "\"");
		ft_strdel(&l->line);
		l->line = tmp;
	}
	old = get_set_default_term(NULL);
	tcsetattr(0, TCSANOW, &old);
}
