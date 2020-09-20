/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:37:15 by tango             #+#    #+#             */
/*   Updated: 2020/09/21 03:54:05 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void			paste_apply_screen(t_l *l, char *clip, int i)
{
	apply_termcap_str("cd", 0, 0);
	ft_putstr(clip);
	apply_termcap_str("sc", 0, 0);
	if (l->line)
		ft_putstr(&l->line[i]);
	apply_termcap_str("rc", 0, 0);
}

static void			wind_up_cursor(t_l *l, int clip_len)
{
	int				starting_row_from_top;
	int				row_position;
	int				nb_rewind;
	int				gap_between_begin_end;

	l->starting_row = (l->nb + clip_len + l->pmpt) / l->co;
	starting_row_from_top = l->total_row - l->starting_row;
	gap_between_begin_end = (l->y * l->co + l->x + clip_len) / l->co;
	row_position = starting_row_from_top + gap_between_begin_end;
	nb_rewind = get_current_row() - row_position;
	while (nb_rewind-- > 0)
	{
		apply_termcap_str("up", 0, 0);
	}
}

static void			unify_space(char *clip)
{
	while (*clip)
	{
		if (*clip == '\n' || *clip == '\t')		
			*clip = ' ';
		++clip;
	}
}

static char			*get_clip(char raw_clip[])
{
	char			*clip;
	char			*temp;
	char			buf[BUFF_LINE_EDITION];
	int				len;

	if (ft_strlen(raw_clip) >= BUFF_LINE_EDITION)
		clip = ft_strndup(raw_clip, BUFF_LINE_EDITION);
	else
		clip = ft_strdup(raw_clip);
	temp = NULL;
	while (read(STDIN_FILENO, buf, BUFF_LINE_EDITION) > 0)
	{
		temp == NULL ? ioctl(0, TIOCSTI, "") : 0;
		temp = ft_strnjoin(clip, buf, BUFF_LINE_EDITION, &len);
		ft_strdel(&clip);
		clip = temp;
		if (len != BUFF_LINE_EDITION)
			break ;
	}
	unify_space(clip);
	return (clip);
}

int					paste(t_l *l, char raw_clip[], int clip_len, int i)
{
	char			*clip;
	char			*tmp;

	if (raw_clip)
		clip = get_clip(raw_clip);
	else if (!(clip = clipboard(NULL, CLIP_TAKE)))
		return (1);
	clip_len = ft_strlen(clip);
	i = l->x + (l->y * l->co) - l->pmpt;
	paste_apply_screen(l, clip, i);
	tmp = ft_strnew(l->nb + clip_len);
	if (l->line)
		tmp = ft_strncpy(tmp, l->line, i);
	tmp = ft_strcat(tmp, clip);
	if (l->line)
		tmp = ft_strcat(tmp, &l->line[i]);
	ft_strdel(&l->line);
	l->line = tmp;
	if (l->starting_row < (l->nb + l->pmpt + clip_len) / l->co)
		wind_up_cursor(l, clip_len);
	paste_background(l, clip_len);
	return (1);
}
