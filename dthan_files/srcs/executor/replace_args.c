/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 02:12:01 by dthan             #+#    #+#             */
/*   Updated: 2020/04/06 02:12:02 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_tild(char *arg)
{
	char		*home;
	char		temp[sysconf(_SC_ARG_MAX)];

	if (arg[0] == '~' && (arg[1] == '\0' || arg[1] == '/'))
	{
		home = ft_call_value_of("HOME");
		ft_bzero(temp, sysconf(_SC_ARG_MAX));
		ft_strcat(temp, &arg[1]);
		ft_strcpy(arg, home);
		ft_strcat(arg, temp);
	}
}

static void	ft_dollar(char *arg)
{
	int			i;
	int			j;
	char		copy[sysconf(_SC_ARG_MAX)];
	char		target[sysconf(_SC_ARG_MAX)];

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '$')
		{
			j = i;
			while (ft_isalnum(arg[++j]))
				NULL;
			ft_bzero(target, sysconf(_SC_ARG_MAX));
			ft_strncpy(target, &arg[i + 1], j - i - 1);
			ft_strcpy(copy, &arg[j]);
			arg[i] = '\0';
			if (ft_call_value_of(target))
			{
				arg[i] = '\0';
				ft_strcat(arg, ft_call_value_of(target));
				ft_strcat(arg, copy);
			}
		}
	}
}

void		ft_replace_args_if_env_var(char **args)
{
	int i;

	i = -1;
	while (args[++i])
	{
		ft_dollar(args[i]);
		if (!ft_input_contain_dquote(args[i]))
			ft_tild(args[i]);
	}
}
