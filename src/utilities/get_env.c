/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:49:46 by ihwang            #+#    #+#             */
/*   Updated: 2020/08/02 02:32:28 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_env(char *name, int keyval)
{
	int		i;
	char	*ret;

	i = -1;
	while (g_env[++i])
	{
		if (keyval == VAL)
		{
			if (ft_strstr(g_env[i], name) && name[0] == g_env[i][0])
				return (ft_strstr_e(g_env[i], name));
		}
		else
		{
			if ((ret = ft_strstr(g_env[i], name)) && name[0] == g_env[i][0])
				return (ret);
		}
	}
	return (NULL);
}
