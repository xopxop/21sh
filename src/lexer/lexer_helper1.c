/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 11:40:09 by dthan             #+#    #+#             */
/*   Updated: 2020/08/05 05:42:26 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_hiphen(char *data)
{
	return (ft_strlen(data) == 1 && data[0] == '-');
}

int		is_separator_operator(char *input, int i)
{
	int front;

	front = i == 0 ? i : i - 1;
	if ((input[i] == '&' && input[front] != '>' && input[front] != '<')
			|| input[i] == ';')
		return (1);
	return (0);
}

int		is_redirection_operator(char *input, int i)
{
	int front;

	front = i == 0 ? i : i - 1;
	if ((input[i] == '&' && (input[front] == '>' || input[front] == '<'))
			|| input[i] == '<' || input[i] == '>')
		return (1);
	return (0);
}

char	*is_pipe_operator(char *input, int i)
{
	return (ft_strchr("|", input[i]));
}
