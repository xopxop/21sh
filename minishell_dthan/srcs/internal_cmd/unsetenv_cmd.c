/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 02:25:02 by dthan             #+#    #+#             */
/*   Updated: 2020/03/30 02:25:03 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_count(char **var_name, char **env)
{
	int i;
	int namelen;

	i = 0;
	while (*env)
	{
		namelen = ft_strlen(*var_name);
		if (!ft_strncmp(*var_name, *env, namelen) && *(*env + namelen) == '=')
		{
			var_name++;
			i++;
		}
		env++;
	}
	return (i);
}

char		**unsetenv_cmd(char **var_name, char **old_env)
{
	char	**new_env;
	char	**new_var;
	char	**ptr_old_var;
	int		size;
	int		namelen;

	if (*var_name)
	{
		size = ft_count(var_name, old_env);
		if (size != 0)
		{
			ptr_old_var = old_env;
			if (!(new_var = (char**)malloc(sizeof(char*) * \
						(ft_string_count(old_env) - size + 1))))
				ft_error_malloc();
			new_env = new_var;
			while (*ptr_old_var)
			{
				namelen = ft_strlen(*var_name);
				if (ft_strncmp(*var_name, *ptr_old_var, namelen) \
					|| (!ft_strncmp(*var_name, *ptr_old_var, namelen) &&  \
						*(*ptr_old_var + namelen) != '='))
				{
					*new_var = ft_strdup(*ptr_old_var);
					new_var++;
				}
				else
					var_name++;
				ptr_old_var++;
			}
			*new_var = NULL;
			ft_free_old_env(old_env);
			return (new_env);
		}
	}
	return (old_env);
}
