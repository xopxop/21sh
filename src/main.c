/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:14:36 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/12 01:36:57 by ihwang           ###   ########.fr       */
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

t_h			*get_history(int fd)
{
	t_h		*h;
	t_h		*node;
	t_h		*tmp;
	char	*line;

	fd = open("./.history", O_RDWR | O_CREAT, 0644);
	if (!get_next_line(fd, &line))
		return (NULL);
	h = (t_h*)malloc(sizeof(t_h));
	h->data = line;
	node = h;
	h->nb = 1;
	while (get_next_line(fd, &line))
	{
		tmp = (t_h*)malloc(sizeof(t_h));
		tmp->data = line;
		node->next = tmp;
		node = node->next;
		h->nb++;
	}
	close(fd);
	node = NULL;
	return (h);
}

static int	shell(void)
{
	t_l		l;
	t_h		*h;

	h = get_history(0);
	while (1)
	{
		sig_controller(PARENT);
		WIFSIGNALED(g_status) ? 0 : get_prompt();
	//	init_term();
		g_status = 0;
		ft_get_line(&l, &h);
//		get_next_line(0, &line);
		is_eof(l.line) ? parse_line(&l.line) : ft_exit(NULL, PRINT);
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
