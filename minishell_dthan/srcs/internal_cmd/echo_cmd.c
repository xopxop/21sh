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

#include "../../includes/minishell.h"

char	**echo_cmd(char **words, char **env)
{
	if (*words != NULL)
	{
		ft_printf(*words);
		words++;
		while (*words)
		{
			ft_printf(" %s", *words);
			words++;
		}
		ft_putchar('\n');
	}
	else
		ft_putchar('\n');
	return (env);
}
