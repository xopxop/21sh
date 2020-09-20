/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_files2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:46:33 by tango             #+#    #+#             */
/*   Updated: 2020/08/05 05:44:57 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_astnode		*io_file4(t_token **token)
{
	t_astnode	*node;
	t_astnode	*childnode;

	*token = (*token)->next;
	if ((childnode = filename(token)) == NULL)
		return (NULL);
	node = build_node(AST_io_file);
	node->data = ft_strdup(">&");
	node->left = childnode;
	return (node);
}

t_astnode		*io_file5(t_token **token)
{
	t_astnode	*node;
	t_astnode	*childnode;

	*token = (*token)->next;
	if ((childnode = filename(token)) == NULL)
		return (NULL);
	node = build_node(AST_io_file);
	node->data = ft_strdup(">>");
	node->left = childnode;
	return (node);
}

t_astnode		*io_file6(t_token **token)
{
	t_astnode	*node;
	t_astnode	*childnode;

	*token = (*token)->next;
	if ((childnode = filename(token)) == NULL)
		return (NULL);
	node = build_node(AST_io_file);
	node->data = ft_strdup("<<");
	node->left = childnode;
	return (node);
}
