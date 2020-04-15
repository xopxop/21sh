/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:41:57 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/16 00:18:11 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	del_replace(int index)
{
	int		nb;
	int		i;
	int		j;
	char	**temp;

	nb = -1;
	while (g_env[++nb])
		NULL;
	temp = (char**)malloc(sizeof(char*) * nb);
	i = -1;
	j = 0;
	while (++i < nb)
	{
		if (i != index)
		{
			temp[j] = (char*)malloc(PATH_MAX);
			ft_strcpy(temp[j++], g_env[i]);
		}
	}
	temp[j] = NULL;
	ft_strlst_del(&g_env, nb + 1);
	g_env = temp;
}

static int	is_env(char *str)
{
	int		i;
	char	*dot;

	i = -1;
	while (g_env[++i])
	{
		dot = ft_strchr(g_env[i], '=');
		*dot = '\0';
		if (!ft_strcmp(g_env[i], str))
		{
			*dot = '=';
			return (i);
		}
		*dot = '=';
	}
	return (0);
}

void		ft_unsetenv(t_exe *c)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	while (++i < c->ac)
	{
		j = -1;
		while (ft_isalnum(c->av[i][++j]))
			NULL;
		if (c->av[i][j] != '\0')
			error_monitor("unsetenv: '", c->av[i], \
					"': not a valid identifier", NULL, EXIT_FAILURE, 0);
		else if ((index = is_env(c->av[i])))
			del_replace(index);
	}
}
