/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:14:36 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/31 22:22:18 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh.h"

void		get_prompt(void)
{
	char	*user;
	char	*home;
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
	ft_putstr("Minishell ");
	if ((home = get_env("HOME=", VAL)))
		/*'get_env' function is simillar with your 'ft_find_env'
		  but the diffrence is, it takes extra parameter 'VAL' or 'KEY'
		  It gets address of very first character in env var when it comes with
		  'KEY' macro.
		  And if it's 'VAL', It returns first address of value
		  For example, in this case, It returns /Users/ihwang
		  But instead of mine, we can use builtin function 'getenv' from now on
		  the result seems same with mine.
		  Additionally, in minishell, every 'get_env' function is surrounded by
		  'if' statement to protect the cases that there is no such env var.
		  This is why I failed on evaluation.
		*/
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
	ft_putstr(" ");
	(user = get_env("USER=", VAL)) ? ft_putstr(user) : 0;
	ft_putstr("$ ");
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
		// from du: i think you should need a bigger bufer for the env for the future, 
		//because, this PATH_MAX macro just for the length of the path, we all so have
		//the name of the variable plus '=' as well.
		env[i] = (char*)malloc(sizeof(char) * PATH_MAX);
		ft_strcat(env[i], sample[i]);
	}
	env[i] = NULL;
	return (env);
}

static int	minishell(void)
{
	char	*input;

	while (1)
	{
		sig_controller(PARENT);
		/*There are two macros PARENT and CHILD for this function
		since all the signal controlings have to be changed to default setting
		when it comes with child process*/
		WIFSIGNALED(g_status) ? 0 : get_prompt();
		g_status = 0;
		input = get_input((int)1);
		is_eof(input) ? parse_line(&input) : ft_exit(NULL, PRINT);
		/*I'm using ft_exit function when user wants to exit, and even in error case.
		  especially, ft_exit takes 'ER'macro when 'execve' is incomplete
		  otherwise, it takes 'PRINT' macro*/
		/*
		   'is_eof' function is for checking if the given input is EOF or not
		*/
	}
	return (0);
}

int			main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	g_env = set_env(envp);
	return (minishell());
}
