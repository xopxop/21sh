/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 02:24:33 by dthan             #+#    #+#             */
/*   Updated: 2020/03/30 02:24:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


//same as ft_find_env but there is slightly change, maybe i will fix it
char	*ft_call_var(char *var_name, char **env)
{
	int i;

	while (*env)
	{
		i = ft_strlen(var_name);
		if (!ft_strncmp(var_name, *env, i))
			if (*(*env + i) == '=')
				return (*env);
		env++;
	}
	return (NULL);
}


char	*ft_erase(char *path)
{
	char *ptr;

	ptr = path;
	ptr = ft_strrchr(ptr, '/');
	while (*ptr)
	{
		*ptr = '\0';
		ptr++;
	}
	return (path);
}

char	*ft_goto_home(char *path, char **env)
{
	char *home;

	home = ft_find_env("HOME", env);
	path = ft_strcpy(path, home);
	return (path);
}

char	*ft_goto_root(char *path)
{
	char *ptr;

	ptr = path;
	*ptr = '/';
	ptr++;
	*ptr = '\0';
	return (path);
}

char	*ft_goto_dir(char *newdir, char *path)
{
	char *ptr;

	ptr = path;
	while(*ptr)
		ptr++;
	*ptr = '/';
	ptr++;
	ptr = ft_strcpy(ptr, newdir);
	return (path);
}

char	*ft_parse_path(char *arg, char **env, char *path)
{
	char **tokens;
	int step;

	if (!(path = (char*)ft_memalloc(PATH_MAX + 1)))
		ft_error_malloc();
	path = getcwd(path, PATH_MAX + 1);
	tokens = ft_strsplit(arg, '/');
	step = 0;
	while (*tokens)
	{
		if (!ft_strcmp(".", *tokens))
			continue ;
		else if (!ft_strcmp("..", *tokens))
			path = ft_erase(path);
		else if (step == 0 && !ft_strcmp("~", *tokens))
			path = ft_goto_home(path, env);
		else if (step == 0 && !ft_strncmp("/", *tokens, 1))
			path = ft_goto_root(path);
		else
			path = ft_goto_dir(*tokens, path);
		step++;
		tokens++;
	}
	return (path);
}

void ft_sth_error(void)
{

}

char	**cd_cmd(char **tokens, char **env)
{
	char *path;

	path = NULL;
	path = ft_parse_path(*tokens, env, path);
	if (*tokens && (access(*tokens, F_OK) == 0))
		chdir(*tokens);
	else if (access(path, F_OK))
		chdir(path);
	else
		ft_sth_error();
	return (env);
}
