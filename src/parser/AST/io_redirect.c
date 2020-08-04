/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 09:24:37 by dthan             #+#    #+#             */
/*   Updated: 2020/08/05 05:44:59 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** io_redirect:           io_file
**            | IO_NUMBER io_file
**            |           io_here
**            | IO_NUMBER io_here
*/

t_astnode		*io_redirect1(t_token **token)
{
	t_astnode	*node;
	t_astnode	*childnode;
	char		*ionumber;

	if (*token == NULL)
		return (NULL);
	if ((*token)->type != TOKEN_IO_NUMBER)
		return (NULL);
	ionumber = (*token)->data;
	*token = (*token)->next;
	if ((childnode = io_file(token)) == NULL)
		return (NULL);
	node = build_node(AST_io_redirect);
	node->data = ft_strdup(ionumber);
	node->right = childnode;
	return (node);
}

t_astnode		*io_redirect2(t_token **token)
{
	return (io_file(token));
}

t_astnode		*io_redirect(t_token **token)
{
	t_astnode	*node;
	t_token		*reset;

	reset = *token;
	if ((node = io_redirect1(token)) != NULL)
		return (node);
	*token = reset;
	if ((node = io_redirect2(token)) != NULL)
		return (node);
	return (NULL);
}
