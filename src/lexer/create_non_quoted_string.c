/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_non_quoted_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:21:33 by tango             #+#    #+#             */
/*   Updated: 2020/08/05 05:42:18 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			*creat_non_quoted_string(char *input, char quote, size_t len)
{
	char		*start;
	char		*end;
	char		*new;
	int			i;
	int			j;

	start = ft_strchr(input, quote);
	end = ft_strrchr(input, quote);
	new = ft_strnew(len - 2);
	i = 0;
	j = 0;
	while (len > 0)
	{
		if (&input[j] != start && &input[j] != end)
			new[i++] = input[j];
		j++;
		len--;
	}
	ft_strdel(&input);
	return (new);
}
