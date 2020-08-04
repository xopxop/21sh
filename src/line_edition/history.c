/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 00:22:24 by ihwang            #+#    #+#             */
/*   Updated: 2020/08/05 05:42:59 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		get_history(t_h **h, int fd)
{
	t_h		*node;
	t_h		*tmp;
	char	*line;

	fd = open("./.history", O_RDWR | O_CREAT, 0644);
	if (!get_next_line(fd, &line))
		return ;
	h[0] = (t_h*)malloc(sizeof(t_h));
	ft_memset(h[0], 0, sizeof(t_h));
	h[0]->data = line;
	h[0]->len = ft_strlen(line);
	h[0]->nb = 1;
	node = h[0];
	while (get_next_line(fd, &line) > 0)
	{
		tmp = (t_h*)malloc(sizeof(t_h));
		ft_memset(tmp, 0, sizeof(t_h));
		tmp->data = line;
		tmp->len = ft_strlen(line);
		node->next = tmp;
		node = node->next;
		h[0]->nb++;
	}
	close(fd);
}

void		append_history(t_l *l, t_h **h)
{
	t_h		*append;

	if (!l->line || !ft_isprint(l->line[0]))
		return ;
	append = (t_h*)malloc(sizeof(t_h));
	ft_memset(append, 0, sizeof(t_h));
	append->nb = h[0] ? h[0]->nb + 1 : 1;
	append->data = ft_strdup(l->line);
	append->len = ft_strlen(append->data);
	append->next = h[0];
	h[0] = append;
	l->curr = 0;
}

void		delete_save_history(t_h **h)
{
	t_h		*trav;
	t_h		*tmp;
	int		fd;

	if (!h[0])
		return ;
	trav = h[0];
	fd = open("./.history", O_RDWR);
	while (trav)
	{
		write(fd, trav->data, trav->len);
		if (trav->next)
			write(fd, "\n", 1);
		ft_strdel(&trav->data);
		tmp = trav->next;
		if (trav)
			free(trav);
		trav = tmp;
	}
	close(fd);
}
