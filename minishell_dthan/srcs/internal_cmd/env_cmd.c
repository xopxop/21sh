/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 02:25:10 by dthan             #+#    #+#             */
/*   Updated: 2020/03/30 02:25:11 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**env_cmd(char **tokens, char **env)
{
	char **ptr;

	ptr = env;
	(void)tokens;
	while (*ptr)
	{
		ft_printf("%s\n", *ptr);
		ptr++;
	}
	return (env);
}
