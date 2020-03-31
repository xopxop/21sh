/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:18:23 by dthan             #+#    #+#             */
/*   Updated: 2020/03/31 17:59:34 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_load_config(char **variable)
{
	char		**list_loaded_variables;
	char		**ptr;

	if (!(list_loaded_variables = (char**)malloc(sizeof(char*) * \
					(ft_string_count(variable) + 1))))
		ft_error_malloc();
	ptr = list_loaded_variables;
	while (*variable)
	{
		*ptr = (char*)ft_memalloc(sizeof(char) * (NAME_MAX + PATH_MAX + 2));
		*ptr = ft_strcpy(*ptr, *variable);
		variable++;
		ptr++;
	}
	*ptr = NULL;
	return (list_loaded_variables);
}

void	ft_promt(char **env)
{
	(void)env;
	ft_putstr("$> ");
}

char	**ft_internal_cmd(char **tokens, char **env, int *ret)
{
	int			i;
	t_command	*get_built_in;

	get_built_in = (t_command[8]) {
		{"echo", echo_cmd},
		{"cd", cd_cmd},
		{"setenv", setenv_cmd},
		{"unsetenv", unsetenv_cmd},
		{"env", env_cmd},
		{"exit", exit_cmd},
		{NULL, NULL}
	};
	i = 0;
	while (get_built_in[i].command)
	{
		if (ft_strcmp(tokens[0], get_built_in[i].command) == 0)
		{
			env = get_built_in[i].func(tokens + 1, env);
			*ret = EXIT_SUCCESS;
			return (env);
		}
		i++;
	}
	return (env);
}

int		ft_external_cmd(char **tokens, char **env)
{
	char **p;
	char *path;

	p = ft_strsplit(ft_find_env("PATH", env), ':');
	while (*p)
	{
		path = ft_strjoin(*p, "/");
		path = ft_strjoin_and_free_string1(path, *tokens);
		if (access(path, F_OK) != -1)
		{
			ft_fork(path, tokens, env);
			free(path);
			return (EXIT_SUCCESS);
		}
		free(path);
		p++;
	}
	// need to free p
	return (EXIT_FAILURE);
}

/*
** need to change the ft_find_built_in
*/

char	**ft_execute(char **tokens, char **env)
{
	int ret;

	ret = EXIT_FAILURE;
	if (tokens[0] != NULL)
	{
		env = ft_internal_cmd(tokens, env, &ret);
		if (ret == EXIT_FAILURE && ft_external_cmd(tokens, env) == EXIT_FAILURE)
			ft_printf("minishell: command not found: %s\n", *tokens);
	}
	return (env);
}

int		main(int argc, char **argv, char **envp)
{
	char	**env;
	char	*line;
	char	**tokens;
	int		ret;

	(void)argc;
	(void)argv;
	env = ft_load_config(envp);
	while (1)
	{
		ft_promt(env);
		if ((ret = get_next_line(0, &line)) <= 0)
			return (EXIT_FAILURE);
		tokens = ft_strsplit(line, ' ');
		env = ft_execute(tokens, env);
		free(line);
	}
	return (EXIT_SUCCESS);
}
