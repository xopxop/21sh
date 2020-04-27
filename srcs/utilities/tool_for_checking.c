/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_for_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 06:21:11 by dthan             #+#    #+#             */
/*   Updated: 2020/04/04 06:21:13 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_open_dquote(char *input, int level)
{
	int matched;
	int i;

	i = -1;
	matched = 0;
	while (input[++i])
		if (input[i] == '"')
			matched++;
	if (level == 1)
		return (((matched % 2) == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
	return (((matched % 2) == 0) ? EXIT_FAILURE : EXIT_SUCCESS);
}

int	input_contain_dquote(char *input)
{
	int i;

	i = -1;
	while (input[++i])
		if (input[i] == '"')
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
