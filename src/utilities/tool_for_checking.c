/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_for_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 06:21:11 by dthan             #+#    #+#             */
/*   Updated: 2020/08/05 05:46:13 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	is_open_dquote(char *input, int level, char *quote)
{
	int matched;
	int i;

	i = 0;
	matched = 0;
	while (input[i] && *quote == '\0')
	{
		if (input[i] == '"' || input[i] == '\'')
		{
			matched++;
			*quote = input[i];
		}
		i++;
	}
	while (input[i])
	{
		if (input[i] == *quote)
			matched++;
		i++;
	}
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
