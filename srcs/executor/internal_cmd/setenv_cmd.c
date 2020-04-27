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

#include "../../../includes/minishell.h"

void	change_var(char *old_value, char *new_value)
{
	if (ft_strcmp(old_value, new_value))
		ft_strcpy(old_value, new_value);
}

void	setenv_cmd(char **tokens)
{
	int		len;
	int		i;
	char	**ptr;

	if (tokens[0] && tokens[1])
	{
		len = ft_strlen(tokens[0]);
		i = -1;
		while (env[++i])
			if (!ft_strncmp(tokens[0], env[i], len) && env[i][len] == '=')
			{
				change_var(env[i] + len + 1, tokens[1]);
				return ;
			}
		if (env[i] == NULL)
		{
			ptr = env;
			env = ft_new_env(tokens[0], tokens[1], 1, env);
			ft_arraydel(ptr);
		}
	}
}
