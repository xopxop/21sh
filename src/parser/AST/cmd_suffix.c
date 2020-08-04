/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_suffix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 09:02:27 by dthan             #+#    #+#             */
/*   Updated: 2020/08/05 05:44:27 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** cmd_suffix :            io_redirect 2
**            | cmd_suffix io_redirect 1
**            |            WORD        4
**            | cmd_suffix WORD        3
*/

t_astnode		*cmd_suffix1(t_token **token)
{
	t_astnode	*node;
	t_astnode	*lnode;
	t_astnode	*rnode;

	if ((lnode = io_redirect(token)) == NULL)
		return (NULL);
	if ((rnode = cmd_suffix(token)) == NULL)
	{
		clear_ast(lnode);
		return (NULL);
	}
	node = build_node(AST_cmd_suffix);
	node->left = lnode;
	node->right = rnode;
	return (node);
}

t_astnode		*cmd_suffix2(t_token **token)
{
	return (io_redirect(token));
}

t_astnode		*cmd_suffix3(t_token **token)
{
	t_astnode	*node;
	t_astnode	*lnode;
	t_astnode	*rnode;

	if ((lnode = word(token)) == NULL)
		return (NULL);
	if ((rnode = cmd_suffix(token)) == NULL)
	{
		ft_delast(lnode);
		return (NULL);
	}
	node = build_node(AST_cmd_suffix);
	node->left = lnode;
	node->right = rnode;
	return (node);
}

t_astnode		*cmd_suffix4(t_token **token)
{
	return (word(token));
}

t_astnode		*cmd_suffix(t_token **token)
{
	t_astnode	*node;
	t_token		*reset;

	reset = *token;
	if ((node = cmd_suffix1(token)) != NULL)
		return (node);
	*token = reset;
	if ((node = cmd_suffix2(token)) != NULL)
		return (node);
	*token = reset;
	if ((node = cmd_suffix3(token)) != NULL)
		return (node);
	*token = reset;
	if ((node = cmd_suffix4(token)) != NULL)
		return (node);
	return (NULL);
}
