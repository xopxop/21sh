/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 17:45:27 by dthan             #+#    #+#             */
/*   Updated: 2020/04/16 18:07:12 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		open_d_quote(char *input, int level)
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

char	*get_input(int level)
{
	char *line;

//	if ((get_next_line(STDOUT_FILENO, &line)) <= 0)
//	STDOUT_FILENO doesn't work on osx
	if ((get_next_line(0, &line)) <= 0)
			return (NULL);
	if (open_d_quote(line, level))
	{
		ft_putstr("dquote> ");
		line = ft_strjoin_and_free_string1(line, "\n");
		line = ft_strjoin_and_free_string2(line, get_input((int)2));
	}
	return (line);
}
