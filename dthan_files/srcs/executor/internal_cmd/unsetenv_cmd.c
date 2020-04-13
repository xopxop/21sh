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

#include "../../../includes/minishell.h"

void		unsetenv_cmd(char **var_name)
{
	char	**ptr;

	if (*var_name && !ft_strncmp(*var_name, ft_call_var(*var_name), \
		ft_strlen(*var_name)))
	{
		ptr = env;
		env = ft_new_env(*var_name, NULL, -1, env);
		ft_arraydel(ptr);
	}
}
