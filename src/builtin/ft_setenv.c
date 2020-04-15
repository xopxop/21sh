/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 00:41:54 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/16 00:11:58 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_env(char *arg)
{
	int		i;
	char	**temp;

	i = -1;
	while (g_env[++i])
		NULL;
	temp = (char**)malloc(sizeof(char*) * (i + 2));
	i = -1;
	while (g_env[++i])
		temp[i] = g_env[i];
	temp[i] = (char*)malloc(sizeof(char) * PATH_MAX);
	ft_strcpy(temp[i], arg);
	temp[i + 1] = NULL;
	free(g_env);
	g_env = temp;
}

static void	ft_setenv_sub(char *arg)
{
	char	**split;
	char	*var;
	int		j;

	split = ft_strsplit(arg, '=');
	if ((var = get_env(split[0], VAL)))
	{
		var++;
		j = 0;
		var[0] = '\0';
		while (split[++j])
			ft_strcat(var, split[j]);
	}
	else
		add_env(arg);
	j = -1;
	while (split[++j])
		NULL;
	ft_strlst_del(&split, j + 1);
}

void		ft_setenv(t_exe *c)
{
	int		i;
	int		j;

	i = 0;
	while (++i < c->ac)
	{
		j = -1;
		while (ft_isalnum(c->av[i][++j]))
			NULL;
		if (c->av[i][j] == '\0')
			;
		else if (c->av[i][j] != '=' || j == 0)
			error_monitor("setenv: '", c->av[i], \
					"'; not a valid identifier", NULL, EXIT_FAILURE, 0);
		else
			ft_setenv_sub(c->av[i]);
	}
}
