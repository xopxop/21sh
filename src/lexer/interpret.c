/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:28:10 by ihwang            #+#    #+#             */
/*   Updated: 2020/05/07 19:27:20 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		interpret_tild(char *str)
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

static void	assign_str_to_node(t_token *node, char *rest, char *target)
{
	char	*temp;

	temp = node->data;
	node->data = ft_strjoin(node->data, get_env(target, VAL));
	ft_strdel(&temp);
	temp = node->data;
	node->data = ft_strjoin(node->data, rest);
	ft_strdel(&temp);
}

void		interpret_dollar(t_token *node)
{
	int			i;
	int			j;
	char		*rest;
	char		*target;

	i = -1;
	while (node->data[++i])
	{
		if (node->data[i] == '$')
		{
			j = i;
			while (ft_isalnum(node->data[++j]))
				NULL;
			target = ft_strnew(j - i);
			ft_strncpy(target, &(node->data)[i + 1], j - i - 1);
			rest = ft_strdup(&(node->data)[j]);
			node->data[i] = '\0';
			if (get_env(ft_strcat(target, "="), VAL))
				assign_str_to_node(node, rest, target);
			ft_strdel(&rest);
			ft_strdel(&target);
		}
	}
}