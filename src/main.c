/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:14:36 by ihwang            #+#    #+#             */
/*   Updated: 2020/08/01 23:57:35 by tango            ###   ########.fr       */
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
		ft_strcpy(env[i], sample[i]);
	}
	env[i] = NULL;
	return (env);
}

/*
** ================= NEW=====================================
*/
void	clear_token(t_token *token)
{
	t_token *temp;

	while (token)
	{
		ft_strdel(&token->data);
		temp = token;
		token = token->next;
		free(temp);
	}
}
static void	ft_execute(char **input)
{
	t_token	*tokens;
	t_astnode *ast;
	char	*trimmed_input;

	ast = NULL;
	trimmed_input = ft_strtrim(*input);
	ft_strdel(input); //freeing for *line of t_l struct
	if (trimmed_input)
	{
		if ((tokens = lexical_analysis(trimmed_input)) != NULL)
		{
			if ((ast = syntax_analysis(tokens)) != NULL)
				executor(ast);
			clear_token(tokens);
		}
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

/*static char	*get_input(int level)
{
	char *line;
	if ((get_next_line(STDOUT_FILENO, &line)) <= 0)
		return (NULL);
	if (is_open_dquote(line, level))
	{
		ft_putstr("dquote> ");
		line = ft_strjoin_and_free_string1(line, "\n");
		line = ft_strjoin_and_free_string2(line, get_input((int)2));
	}
	return (line);
}*/
static char	*get_input(int level, int count_pmpt, char *quote)
{
	t_l l;

	ft_memset(&l, 0, sizeof(t_l));
	if (level != 1)
		l.type = LINE_TYPE_DQUOTE;
	l.pmpt = count_pmpt;
	ft_get_line(&l, &g_h);
	if (is_open_dquote(l.line, level, quote))
	{
		ft_putstr("dquote> ");
		l.line = ft_strjoin_and_free_string1(l.line, "\n");
		l.line = ft_strjoin_and_free_string2(l.line, get_input((int)2, 8, quote));
	}
	return (l.line);
}

static int	minishell(void)
{
	char *line;
	char quote;

	get_history(&g_h, 0);
	while (1)
	{
		sig_controller(PARENT); 
		//WIFSIGNALED(g_status) ? 0 : get_prompt();
		get_prompt();
		g_status = 0;
		quote = '\0';
		line = get_input(1, 2, &quote);
		if (!iseof_in_line(line))
			ft_execute(&line);
		//is_eof(line) ? ft_execute(&line) : 0;
	}
	return (0);
}

/*static int	minishell(void)
{
	t_l		l;

	get_history(&g_h, 0);
	while (1)
	{
		// sig_controller(PARENT); turn off signal for now
		WIFSIGNALED(g_status) ? 0 : get_prompt();
		g_status = 0;
		get_input(1);
		ft_get_line(&l, &g_h);
		// is_eof(input) ? ft_execute(input) : ft_exit(NULL, PRINT);
		//is_eof(input) ? ft_execute(input) : 0;
		is_eof(l.line) ? ft_execute(&l.line) : 0;
	}
	return (0);
}
*/

void		increment_shlvl(void)
{
	char	*shlvl;
	int		nb;
	char	*ascii;

	shlvl = get_env("SHLVL", VAL);
	shlvl++;
	nb = ft_atoi(shlvl);
	nb++;
	ascii = ft_itoa(nb);
	ft_strcpy(shlvl, ascii);
	ft_strdel(&ascii);
}

int			main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	g_env = set_env(envp);
	increment_shlvl();
	if (!(getenv("TERM")))
	{
		ft_putstr_fd("Environment variable 'TERM' not set\n", 2);
		return (-1);
	}
	return (minishell());
}
