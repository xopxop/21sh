/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 10:16:43 by dthan             #+#    #+#             */
/*   Updated: 2020/05/06 15:48:03 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

t_astnode *io_file1(t_token **token)
{
	t_astnode *node;
	t_astnode *childnode;

	*token = (*token)->next;
	if ((childnode = filename(token)) == NULL)
		return (NULL);
	node = build_node(AST_io_file);
	node->data = ft_strdup("<");
	node->left = childnode;
	return (node);
}

t_astnode *io_file2(t_token **token)
{
 	t_astnode *node;
	t_astnode *childnode;

	*token = (*token)->next;
	if (*token == NULL)
		return (NULL);
	if ((childnode = filename(token)) == NULL)
		return (NULL);
	node = build_node(AST_io_file);
	node->data = ft_strdup("<&");
	node->left = childnode;
	return (node);
}

t_astnode *io_file3(t_token **token)
{
	t_astnode *node;
	t_astnode *childnode;

	*token = (*token)->next;
	if ((childnode = filename(token)) == NULL)
		return (NULL);
	node = build_node(AST_io_file);
	node->data = ft_strdup(">");
	node->left = childnode;
	return (node);
}

t_astnode *io_file4(t_token **token)
{
	t_astnode *node;
	t_astnode *childnode;

	*token = (*token)->next;
	if ((childnode = filename(token)) == NULL)
		return (NULL);
	node = build_node(AST_io_file);
	node->data = ft_strdup(">&");
	node->left = childnode;
	return (node);
}

t_astnode *io_file5(t_token **token)
{
	t_astnode *node;
	t_astnode *childnode;

	*token = (*token)->next;
	if ((childnode = filename(token)) == NULL)
		return (NULL);
	node = build_node(AST_io_file);
	node->data = ft_strdup(">>");
	node->left = childnode;
	return (node);
}

t_astnode *io_file6(t_token **token) //not << , it is '<>'
{
	t_astnode *node;
	t_astnode *childnode;

	*token = (*token)->next;
	if ((childnode = filename(token)) == NULL)
		return (NULL);
	node = build_node(AST_io_file);
	node->data = ft_strdup("<<");
	node->left = childnode;
	return (node);
}

// t_astnode *io_file7(t_token **token)
// {
// 	t_astnode *node;
// 	t_astnode *childnode;

// 	if (*token == NULL)
// 		return (NULL);
// 	if ((childnode = filename(token)) == NULL)
// 		return (NULL);
// 	node = build_node(AST_io_file);
// 	node->data = ft_strdup(">|");
// 	node->left = childnode;
// 	return (node);
// }

t_astnode *io_file(t_token **token)
{
	if (*token == NULL)
		return (NULL);
	if (ft_strcmp((*token)->data, "<") == 0)
		return (io_file1(token));
	if (ft_strcmp((*token)->data, "<&") == 0)
	 	return (io_file2(token));
	if (ft_strcmp((*token)->data, ">") == 0)
		return (io_file3(token));
	if (ft_strcmp((*token)->data, ">&") == 0)
		return (io_file4(token));
	if (ft_strcmp((*token)->data, ">>") == 0)
		return (io_file5(token));
	if (ft_strcmp((*token)->data, "<<") == 0)  // need to change to <>
		return (io_file6(token));
	// if (ft_strcmp((*token)->data, ">|") == 0)
	// {
	// 	node = io_file7(token);
	// 	return (node);
	// }
	return (NULL);
}
