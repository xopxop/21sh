/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:22:31 by tango             #+#    #+#             */
/*   Updated: 2020/08/05 05:42:14 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			check_syntax(t_token *lst_tokens)
{
	t_token	*ptr;
	char	buf[3];

	ptr = lst_tokens;
	ft_bzero(buf, 3);
	if (ptr && ptr->type == TOKEN_SEMI)
	{
		return (error_monitor(SYNTAX_UNEXPECTED_TOKEN, ";", "'", 1));
	}
	while (ptr)
	{
		if (ptr->type == TOKEN_WORD && (is_separator_operator(ptr->data, 0) \
					|| is_redirection_operator(ptr->data, 0)))
		{
			return (error_monitor(SYNTAX_UNEXPECTED_TOKEN,\
			ft_strncpy(buf, ptr->data, 2), "'", 1));
		}
		ptr = ptr->next;
	}
	return (EXIT_SUCCESS);
}
