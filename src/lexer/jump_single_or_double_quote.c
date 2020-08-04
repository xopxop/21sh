/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_single_or_double_quote.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:21:04 by tango             #+#    #+#             */
/*   Updated: 2020/08/05 05:42:24 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			jump_single_or_double_quote(char *input, int *tail, char quote)
{
	while (input[++(*tail)])
		if (input[*tail] == quote)
			break ;
	return (quote);
}
