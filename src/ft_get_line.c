/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 19:13:18 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/12 23:48:44 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				apply_termcap_str(char *str, int x, int y)
{
	if (!ft_strcmp(str, "ch"))
		ft_putstr_fd(tgoto(tgetstr("ch", NULL), x, y), 0);
	else if (x && y)
		NULL;
	else if (y)
		ft_putstr_fd(tgoto(tgetstr(str, NULL), 0, y), 0);
	else
		ft_putstr_fd(tgetstr(str, NULL), 0);
}

t_term				default_term(t_term *t)
{
	static t_term	old;

	if (t)
		old = *t;
	return (old);
}

void				init_term(t_l *l, t_h **h)
{
	t_term			t;

	ft_memset(l, 0, sizeof(t_l));
	l->x = PMPT;
	tcgetattr(0, &t);
	default_term(&t);
	t.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t);
	if (!(tgetent(NULL, getenv("TERM"))))
	{
		ft_putstr_fd("Environment variable 'TERM' not set \n", 2);
		ft_exit(NULL, ER, h);
	}
	l->co = tgetnum("co");
}

static void			bs_key_str(t_l *l)
{
	int				i;

	if (l->y == 0)
	{
		ft_putstr(&l->line[l->x - PMPT]);
		i = l->x - 2 - PMPT;
		l->x--;
	}
	else
	{
		ft_putstr(&l->line[l->x + (l->co * l->y) - PMPT]);
		i = l->x + (l->co * l->y) - 2 - PMPT;
		if (l->x == 0)
		{
			l->x = l->co - 1;
			l->y--;
		}
		else
			l->x--;
	}
	while (++i < l->nb)
		l->line[i] = l->line[i + 1];
	l->nb--;
}

int					bs_key(t_l *l)
{
	if (l->y == 0 && l->x == PMPT)
		return (1);
	apply_termcap_str("#4", 0, 0);
	apply_termcap_str("cd", 0, 0);
	apply_termcap_str("sc", 0, 0);
	bs_key_str(l);
	apply_termcap_str("rc", 0, 0);
	return (1);
}

void				left_key(t_l *l)
{
	if (l->x == PMPT && l->y == 0)
		return ;
	if (l->x == 0 && l->y != 0)
	{
		l->y--;
		l->x = l->co - 1;
		apply_termcap_str("#4", 0, 0);
	}
	else
	{
		apply_termcap_str("#4", 0, 0);
		l->x--;
	}
}

void				right_key(t_l *l)
{
	if (l->x + (l->y * l->co) - PMPT == l->nb)
		return ;
	if (l->x != l->co - 1)
	{
		apply_termcap_str("nd", 0, 0);
		l->x++;
	}
	else
	{
		apply_termcap_str("do", 0, 0);
		l->x = 0;
		l->y++;
	}
}

void				append_char(char t[], t_l *l)
{
	char			*tmp;

	if (l->line == NULL)
		l->line = ft_strnew(2);
	tmp = ft_strjoin(l->line, t);
	ft_strdel(&l->line);
	l->line = tmp;
	ft_putstr(&l->line[l->nb]);
	if (l->x != l->co - 1)
		l->x++;
	else
	{
		l->x = 0;
		l->y++;
	}
	l->nb++;
}

void				insert_char(char t[], t_l *l)
{
	char			*tmp;

	tmp = ft_strnew(l->nb + 1);
	tmp = ft_strncpy(tmp, l->line, l->x + (l->y * l->co) - PMPT);
	tmp = ft_addchar(tmp, t[0]);
	tmp = ft_strcat(tmp, &l->line[l->x + (l->y * l->co) - PMPT]);
	ft_strdel(&l->line);
	l->line = tmp;
	ft_putchar(t[0]);
	if (l->x != l->co - 1)
		apply_termcap_str("cd", 0, 0);
	else
		apply_termcap_str("do", 0, 0);
	apply_termcap_str("sc", 0, 0);
	ft_putstr(&l->line[l->x + (l->y * l->co) - PMPT + 1]);
	apply_termcap_str("rc", 0, 0);
	if (l->x != l->co - 1)
		l->x++;
	else
	{
		l->x = 0;
		l->y++;
	}
	l->nb++;
}

void				add_key(char t[], t_l *l)
{
	if (l->nb != l->x + (l->co * l->y) - PMPT)
		insert_char(t, l);
	else
		append_char(t, l);
}

char				*clipboard(char *str, int opt)
{
	static char		*clip;

	if (opt == CLIP_SAVE)
	{
		if (clip)
			ft_strdel(&clip);
		clip = ft_strdup(str);
	}
	else if (opt == CLIP_TAKE)
	{
		if (clip)
			return (clip);
	}
	else
		ft_strdel(&clip);
	return (NULL);
}

void				ctrl_left_for_zero(t_l *l, int y_dec)
{
	l->x = PMPT;
	l->y = 0;
	while (y_dec--)
		apply_termcap_str("up", 0, 0);
	apply_termcap_str("ch", 0, PMPT);
}

void				ctrl_left(t_l *l, int y_dec)
{
	int				i;
	int				curr;

	i = l->x + (l->y * l->co) - PMPT;
	curr = i;
	ft_iswhite(l->line[i - 1]) && !ft_iswhite(l->line[i]) && i ? i-- : 0;
	while (i >= 0)
	{
		if (i == 0)
			ctrl_left_for_zero(l, y_dec);
		else if (ft_iswhite(l->line[i - 1]) && !ft_iswhite(l->line[i]))
		{
			if (l->x < curr - i)
			{
				l->y -= y_dec;
				while (y_dec--)
					apply_termcap_str("up", 0, 0);
			}
			apply_termcap_str("ch", 0, (i + PMPT) % l->co);
			l->x = (i + PMPT) % l->co;
			break ;
		}
		(i + PMPT) % l->co == 0 ? y_dec++ : 0;
		i--;
	}
}

void				ctrl_k_clipping(t_l *l, int i, int j)
{
	char			*clip;

	clip = ft_strnew(j - i);
	clip = ft_strncpy(clip, &l->line[i], j - i);
	clipboard(clip, CLIP_SAVE);
	ft_strdel(&clip);
}

void				ctrl_k_edit_line(t_l *l, int i, int j)
{
	char			*tmp;

	tmp = ft_strnew(l->nb - (j - i));
	tmp = ft_strncpy(tmp, l->line, i);
	tmp = ft_strcat(tmp, &l->line[j]);
	ft_strdel(&l->line);
	l->line = tmp;
}

void				ctrl_k_apply_to_screen(t_l *l, int i, int j, int y_dec)
{
	if (l->x < l->x + (l->y * l->co) - PMPT - i)
	{
		l->y -= y_dec;
		while (y_dec--)
			apply_termcap_str("up", 0, 0);
	}
	apply_termcap_str("ch", 0, (i + PMPT) % l->co);
	l->x = (i + PMPT) % l->co;
	apply_termcap_str("cd", 0, 0);
	apply_termcap_str("sc", 0, 0);
	ft_putstr(&l->line[i]);
	apply_termcap_str("rc", 0, 0);
	l->nb -= (j - i);
}

int					ctrl_k(t_l *l, int y_dec)
{
	int				curr;
	int				i;
	int				j;

	i = l->x + (l->y * l->co) - PMPT;
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
		(i + PMPT) % l->co == 0 ? y_dec++ : 0;
		i--;
	}
	return (1);
}

void				ctrl_p_apply_screen(t_l *l, char *clip, int i)
{
	apply_termcap_str("cd", 0, 0);
	ft_putstr(clip);
	apply_termcap_str("sc", 0, 0);
	ft_putstr(&l->line[i]);
	apply_termcap_str("rc", 0, 0);
}

int					ctrl_p(t_l *l, int clip_len)
{
	char			*clip;
	char			*tmp;
	int				i;

	if (!(clip = clipboard(NULL, CLIP_TAKE)))
		return (1);
	clip_len = ft_strlen(clip);
	i = l->x + (l->y * l->co) - PMPT;
	ctrl_p_apply_screen(l, clip, i);
	tmp = ft_strnew(l->nb + clip_len);
	tmp = ft_strncpy(tmp, l->line, i);
	tmp = ft_strcat(tmp, clip);
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

int					parse_key(char t[], t_l *l)
{
	if (t[0] == 127 && t[1] == '\0')
		return (bs_key(l));
	else if (t[0] == '\v' && t[1] == '\0')
		return (ctrl_k(l, 0));
	else if (t[0] == 16 && t[1] == '\0')
		return (ctrl_p(l, 0));
	return (0);
}

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

void				ctrl_right(t_l *l)
{
	int				i;
	int				y_inc;

	y_inc = 0;
	i = l->x + (l->y * l->co) - PMPT;
	(ft_iswhite(l->line[i - 1]) && !ft_iswhite(l->line[i]) && i) ? i++ : 0;
	while (i <= l->nb)
	{
		if ((ft_iswhite(l->line[i - 1]) && !ft_iswhite(l->line[i]) && i)
				|| i == l->nb)
		{
			if (i + PMPT - (l->x + (l->y * l->co)) >= l->co - l->x)
			{
				l->y += y_inc;
				while (y_inc--)
					apply_termcap_str("do", 0, 0);
			}
			apply_termcap_str("ch", 0, (i + PMPT) % l->co);
			l->x = (i + PMPT) % l->co;
			break ;
		}
		((i + PMPT) % l->co == l->co - 1) ? y_inc++ : 0;
		i++;
	}
}

void				up_down_key_apply_statuses(t_l *l)
{
	int				i;

	i = l->y;
	while (i--)
		apply_termcap_str("up", 0, 0);
	apply_termcap_str("ch", 0, PMPT);
	apply_termcap_str("cd", 0, 0);
	l->nb = ft_strlen(l->line);
	l->y = (l->nb + PMPT) / l->co;
	l->x = (l->nb + PMPT) % l->co;
	ft_putstr(l->line);
}

t_h					*append_history(t_l *l, t_h **h)
{
	t_h				*append;

	if (!l->line || !ft_isprint(l->line[0]))
		return (h[0]);
	append = (t_h*)malloc(sizeof(t_h));
	append->nb = h[0] ? h[0]->nb + 1 : 1;
	append->data = ft_strdup(l->line);
	append->len = ft_strlen(append->data);
	append->next = h[0];
	h[0] = append;
	l->curr = 0;
	return (h[0]);
}

void				up_key(t_l *l, t_h **h)
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

void				down_key(t_l *l, t_h **h, char *first)
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
		//clear tmp
		ft_strdel(&tmp);
	else if (t[0] == 27 && t[1] == 91 && t[2] == 'A')
//	else if (t[0] == 'u')
	{
		if (l->curr == 0 && l->line && ft_isprint(l->line[0]))
			tmp = ft_strdup(l->line);
		up_key(l, h);
	}
//	else if (t[0] == 'd')
	else if (t[0] == 27 && t[1] == 91 && t[2] == 'B')
		down_key(l, h, tmp);

}

void				delete_save_history(t_h **h)
{
	t_h				*trav;
	t_h				*tmp;
	int				fd;

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
		free(trav);
		trav = tmp;
	}
	close(fd);
}

void				parse_key_esc(char t[], t_l *l, t_h **h)
{
	if ((t[0] == 27 && t[1] == 91 && t[2] == 'A')
		|| (t[0] == 27 && t[1] == 91 && t[2] == 'B'))
//	if (t[0] == 'u' || t[0] == 'd')
		up_down(l, h, t);
	else if  (t[0] == 27 && t[1] == 91 && t[2] == 'D')
		left_key(l);
	else if (t[0] == 27 && t[1] == 91 && t[2] == 'C')
		right_key(l);
	else if (!ft_strcmp(t, "\x1b[1;5A"))
		ctrl_up(l);
	else if (!ft_strcmp(t, "\x1b[1;5B"))
		ctrl_down(l);
	else if (!ft_strcmp(t, "\x1b[1;5C"))
		ctrl_right(l);
	else if (!ft_strcmp(t, "\x1b[1;5D"))
		ctrl_left(l, 0);
	else if (ft_isprint(t[0]))
		add_key(t, l);
}

void				restore_term(t_l *l)
{
	t_term			old;

	if (l->line == NULL)
		add_key("\n", l);
	apply_termcap_str("do", 0, 0);
	old = default_term(NULL);
	tcsetattr(0, TCSANOW, &old);
}

void				ft_get_line(t_l *l, t_h **h)
{
	char			tmp[8];

	init_term(l, h);
	while (1)
	{
		ft_bzero(tmp, sizeof(tmp));
		read(0, tmp, sizeof(tmp));
		if (tmp[0] == '\n')
		{
			h[0] = append_history(l, h);
			up_down(l, h, NULL);
			restore_term(l);
			return ;
		}
		if (!parse_key(tmp, l))
			parse_key_esc(tmp, l, h);
	}
}
