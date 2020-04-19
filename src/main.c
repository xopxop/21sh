/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:14:36 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/19 21:54:16 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

/*
** ================= NEW=====================================
*/

static void	ft_execute(char *input, t_h **h)
{
	t_token	*tokens;
	t_astnode *ast;
	char	*trimmed_input;

	ast = NULL;
	trimmed_input = ft_strtrim(input);
	if (trimmed_input)
	{
		if ((tokens = lexical_analysis(trimmed_input)) != NULL)
			if ((ast = syntax_analysis(tokens)) != NULL)
				executor(ast, h);
		free(trimmed_input); // need to free tokens after, i can free them all at executor
	}
}

/*
** ============================================================
*/

// OLD
// static int	minishell(void)
// {
// 	char	*input;

// 	while (1)
// 	{
// 		sig_controller(PARENT);
// 		WIFSIGNALED(g_status) ? 0 : get_prompt();
// 		g_status = 0;
// 		input = get_input((int)1);
// 		is_eof(input) ? parse_line(&input) : ft_exit(NULL, PRINT);
// 	}
// 	return (0);
// }

// NEW

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



static int	minishell(void)
{
	t_l		l;
	t_h		*h;

	h = NULL;
	get_history(&h, 0);
	while (1)
	{
		// sig_controller(PARENT); turn off signal for now
		WIFSIGNALED(g_status) ? 0 : get_prompt();
		g_status = 0;
		ft_get_line(&l, &h);
		// is_eof(input) ? ft_execute(input) : ft_exit(NULL, PRINT);
		//is_eof(input) ? ft_execute(input) : 0;
		//is_eof(l.line) ? ft_execute(l.line, &h) : 0;
		ft_execute(l.line, &h);

	}
	return (0);
}

int			main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	g_env = set_env(envp);
	if (!(getenv("TERM")))
	{
		ft_putstr_fd("Environment variable 'TERM' not set\n", 2);
		return (-1);
	}
	return (minishell());
}
