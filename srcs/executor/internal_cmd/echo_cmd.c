/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 02:24:28 by dthan             #+#    #+#             */
/*   Updated: 2020/03/30 02:24:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#define Y 1
#define N 0

void	echo_cmd(char **args)
{
	int i;

	i = -1;
	if (args[++i])
	{
		ft_putstr(args[i]);
		while (args[++i])
		{
			ft_putchar(' ');
			ft_putstr(args[i]);
		}
	}
	ft_putchar('\n');
}
