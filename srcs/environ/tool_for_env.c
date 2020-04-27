/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_for_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 06:16:45 by dthan             #+#    #+#             */
/*   Updated: 2020/04/04 06:16:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_new_env(char *var_name, char *var_value, int step, char **env)
{
	char	**ptr_new_env;
	char	**new_env;
	int		i;

	i = -1;
	ptr_new_env = NULL;
	new_env = (char**)malloc(sizeof(char*) * (ft_arrayct(env) + step + 1));
	ptr_new_env = new_env;
	while (env[++i])
	{
		if (step == -1 && !ft_strncmp(var_name, env[i], ft_strlen(var_name)))
			continue ;
		*new_env = (char*)ft_memalloc((sizeof(char) * sysconf(_SC_ARG_MAX)));
		*new_env = ft_strcpy(*new_env, env[i]);
		new_env++;
	}
	if (var_name && var_value && step == 1)
	{
		*new_env = (char*)ft_memalloc((sizeof(char) * sysconf(_SC_ARG_MAX)));
		*new_env = ft_strcpy(*new_env, var_name);
		*new_env = ft_strcat(*new_env, "=");
		*new_env = ft_strcat(*new_env, var_value);
		new_env++;
	}
	new_env = NULL;
	return (ptr_new_env);
}

char	*ft_call_var(char *var_name)
{
	int i;
	int len;

	i = -1;
	while (env[++i])
	{
		len = ft_strlen(var_name);
		if (!ft_strncmp(var_name, env[i], len))
			if (env[i][len] == '=')
				return (env[i]);
	}
	return (NULL);
}

char	*ft_call_value_of(char *var_name)
{
	char *p;

	return ((p = ft_call_var(var_name)) != NULL) ? \
	&*(p + ft_strlen(var_name) + 1) : &*p;
}
