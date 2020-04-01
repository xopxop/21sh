/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intpt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:28:10 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/28 19:03:22 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh.h"

static void		tild_intp(char *str)
{
	char		*home;
	char		temp[PATH_MAX];

	if (str[0] == '~' && (str[1] == '\0' || str[1] == '/'))
	{
		home = get_env("HOME=", VAL);
		ft_bzero(temp, PATH_MAX);
		ft_strcat(temp, &str[1]);
		ft_strcpy(str, home);
		ft_strcat(str, temp);
	}
}

static void		dollar_intp(char *str)
{
	int			i;
	int			j;
	char		copy[PATH_MAX];
	char		target[PATH_MAX];

	i = -1;
	while (str[++i])
	{
		if (str[i] == '$')
		{
			j = i;
			while (ft_isalnum(str[++j]))
				NULL;
			ft_bzero(target, PATH_MAX);
			ft_strncpy(target, &str[i + 1], j - i - 1);
			ft_strcpy(copy, &str[j]);
			str[i] = '\0';
			if (get_env(ft_strcat(target, "="), VAL))
			{
				str[i] = '\0';
				ft_strcat(str, get_env(target, VAL));
				ft_strcat(str, copy);
			}
		}
	}
}

void			apply_t_d(t_cmd *c)
{
	int			i;

	i = -1;
	while (++i < c->ac)
	{
		tild_intp(c->av[i]);
		dollar_intp(c->av[i]);
	}
}
