/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_for_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 03:47:08 by dthan             #+#    #+#             */
/*   Updated: 2020/04/02 03:47:09 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	ft_lststrdel(char ***str)
{
	char **ptr;

	while(*str)
	{
		ptr = *str;
		str++;
		ft_strdel(ptr);
	}
	ft_strdel(*str);
}

int		cmd_contains_pipe(char *cmd_input)
{
	while(*cmd_input)
		if (*(cmd_input++) == '|')
			return (YES);
	return (NO);
}

void	parse_cmd(char *cmd_input, int *ret)
{
	t_cmd	*lst;
	char	*path;

	path = NULL;
	lst = get_coms(cmd_input);
	while (lst != NULL)
	{
		apply_t_d(lst);
		
	}
}