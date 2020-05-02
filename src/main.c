/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:14:36 by ihwang            #+#    #+#             */
/*   Updated: 2020/05/03 21:32:25 by tango            ###   ########.fr       */
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

static void	ft_execute(char *input)
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
				executor(ast);
		ft_strdel(&trimmed_input); // need to free tokens after, i can free them all at executor
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


static int	minishell(void)
{
	t_l		l;

	get_history(&g_h, 0);
	while (1)
	{
		// sig_controller(PARENT); turn off signal for now
		WIFSIGNALED(g_status) ? 0 : get_prompt();
		g_status = 0;
		ft_get_line(&l, &g_h);
		// is_eof(input) ? ft_execute(input) : ft_exit(NULL, PRINT);
		//is_eof(input) ? ft_execute(input) : 0;
		is_eof(l.line) ? ft_execute(l.line) : 0;
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
