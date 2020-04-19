/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:14:36 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/13 17:18:39 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		get_prompt(void)
{
	char	*usr;
	char	*home;
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
	ft_putstr("21sh ");
	(usr = get_env("USER=", VAL)) ? ft_putstr(usr) : 0;
	ft_putstr(" ");
	if ((home = get_env("HOME=", VAL)))
	{
		if (!ft_strcmp(pwd, home))
			ft_putstr(pwd);
		else if (ft_strstr(pwd, home))
		{
			ft_putstr("~");
			ft_putstr(ft_strstr_e(pwd, home));
		}
		else
			ft_putstr(pwd);
	}
	else
		ft_putstr(pwd);
	ft_putstr("\n> ");
}

static char	**set_env(char **sample)
{
	char	**env;
	int		i;

	i = -1;
	while (sample[++i])
		NULL;
	env = (char**)malloc(sizeof(char*) * (i + 1));
	i = -1;
	while (sample[++i])
	{
		env[i] = (char*)malloc(sizeof(char) * PATH_MAX);
		ft_strcat(env[i], sample[i]);
	}
	env[i] = NULL;
	return (env);
}

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

static int	shell(void)
{
	t_l		l;
	t_h		*h;

	h = NULL;
	get_history(&h, 0);
	while (1)
	{
		sig_controller(PARENT);
		WIFSIGNALED(g_status) ? 0 : get_prompt();
		g_status = 0;
		ft_get_line(&l, &h);
		is_eof(l.line) ? parse_line(&l.line, &h) : ft_exit(NULL, PRINT, &h);
	}
	return (0);
}

int			main(int ac, char **av, char **envp)
{
	ac = 0;
	av = NULL;
	g_env = set_env(envp);
	if (!(getenv("TERM")))
	{
		ft_putstr_fd("Environment variable 'TERM' not set\n", 2);
		return (-1);
	}
	return (shell());
}
