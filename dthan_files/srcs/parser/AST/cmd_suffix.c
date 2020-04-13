/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_suffix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 09:02:27 by dthan             #+#    #+#             */
/*   Updated: 2020/04/11 09:02:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

/*
** cmd_suffix :            io_redirect
**            | cmd_suffix io_redirect
**            |            WORD       
**            | cmd_suffix WORD       
*/

// t_astnode *cmd_suffix1(t_token **token)
// {
// 	t_astnode *node;
// 	t_astnode *childnode;

// 	if ((childnode = io_redirect(token)) == NULL)
// 		return (NULL);
// 	node = build_node(AST_cmd_suffix);
// 	node->data = ft_strdup("cmd_suffix1");
// 	node->left = childnode;
// 	node->right = NULL;
// 	return (node);
// }

// t_astnode *cmd_suffix2(t_token **token)
// {
// 	t_astnode *node;
// 	t_astnode *lnode;
// 	t_astnode *rnode;

// 	if ((lnode = io_redirect(token)) == NULL)
// 		return (NULL);
// 	if ((rnode = cmd_suffix(token)) == NULL)
// 	{
// 		ft_delast(lnode);
// 		return (NULL);
// 	}
// 	node = build_node(AST_cmd_suffix);
// 	node->data = ft_strdup("cmd_suffix2");
// 	node->left = lnode;
// 	node->right = rnode;
// 	return (node);
// }

t_astnode *cmd_suffix3(t_token **token)
{
	t_astnode *node;
	t_astnode *lnode;
	t_astnode *rnode;

	if ((lnode = word(token)) == NULL)
		return (NULL);
	if ((rnode = cmd_suffix(token)) == NULL)
	{
		ft_delast(lnode);
		return (NULL);
	}
	node = build_node(AST_cmd_suffix);
	node->data = ft_strdup("cmd_suffix4");
	node->left = lnode;
	node->right = rnode;
	return (node);
}

t_astnode *cmd_suffix4(t_token **token)
{
	t_astnode *node;
	t_astnode *childnode;

	if ((childnode = word(token)) == NULL)
		return (NULL);
	node = build_node(AST_cmd_suffix);
	node->data = ft_strdup("cmd_suffix3");
	node->left = childnode;
	node->right = NULL;
	return (node);
}

t_astnode *cmd_suffix(t_token **token)
{
	t_astnode	*node;
	t_token		*reset;
	
	reset = *token;
	// if ((node = cmd_suffix1(token)) != NULL)
	// 	return (node);
	// if ((node = cmd_suffix2(token)) != NULL)
	// 	return (node);
	if ((node = cmd_suffix3(token)) != NULL)
		return (node);
	*token = reset;
	if ((node = cmd_suffix4(token)) != NULL)
		return (node);
	return (NULL);
}
