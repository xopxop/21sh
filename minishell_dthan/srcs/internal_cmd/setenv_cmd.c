/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 02:24:43 by dthan             #+#    #+#             */
/*   Updated: 2020/03/30 02:24:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*change_env(char *var_name, char *var_value, char *var)
{
	int namelen;

	namelen = ft_strlen(var_name);
	if (ft_strcmp(var_value, var + (1 + namelen)) != 0)
		ft_memcpy(var + namelen + 1, var_value, ft_strlen(var_value) + 1);
	return (var);
}

char	*add_last(char *var_name, char *var_value, char *var)
{
	char *ptr;

	ptr = var;
	while (*var_name)
		*ptr++ = *var_name++;
	*ptr++ = '=';
	while (*var_value)
		*ptr++ = *var_value++;
	return (var);
}

char	**add_env(char *var_name, char *var_value, char **old_env)
{
	char **new_var;
	char **new_env;
	char **ptr_old_var;

	ptr_old_var = old_env;
	if (!(new_var = (char**)malloc(sizeof(char*) * (ft_string_count(old_env) + 2))))
		ft_error_malloc();
	new_env = new_var;
	while (*ptr_old_var)
	{
		*new_var = ft_strdup(*ptr_old_var);
		ptr_old_var++;
		new_var++;
	}
	*new_var = (char*)ft_memalloc(sizeof(char) * (NAME_MAX + PATH_MAX + 2));
	*new_var = add_last(var_name, var_value, *new_var);
	new_var++;
	*new_var = NULL;
	ft_free_old_env(old_env);
	return (new_env);
}

char	**setenv_cmd(char **tokens, char **env)
{
	int		len;
	char	**ptr_env;

	if (tokens[0] && tokens[1])
	{
		ptr_env = env;
		len = ft_strlen(tokens[0]);
		while (*ptr_env)
		{
			if (!ft_strncmp(tokens[0], *ptr_env, len) && *(*ptr_env + len) == '=')
			{
				*ptr_env = change_env(tokens[0], tokens[1], *ptr_env);
				break ;
			}
			ptr_env++;
		}
		if (*ptr_env == NULL)
			env = add_env(tokens[0], tokens[1], env);
	}
	return (env);
}
