/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_here.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 10:00:39 by dthan             #+#    #+#             */
/*   Updated: 2020/04/11 10:00:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

// t_astnode *io_here1(t_token **token)
// {
// 	t_astnode *node;
// 	t_astnode *childnode;

// 	if (*token == NULL)
// 		return (NULL);
// 	if ((childnode = here_end(token)) == NULL)
// 		return (NULL);
// 	node = build_node(AST_io_here);
// 	node->data = ft_strdup("<<");
// 	node->left = childnode;
// 	return (node);
// }

// t_astnode *io_here2(t_token **token)
// {
// 	t_astnode *node;
// 	t_astnode *childnode;

// 	if (*token == NULL)
// 		return (NULL);
// 	if ((childnode = here_end(token)) == NULL)
// 		return (NULL);
// 	node = build_node(AST_io_here);
// 	node->data = ft_strdup("<<-");
// 	node->left = childnode;
// 	return (node);
// }

// t_astnode *io_here(t_token **token)
// {
// 	t_astnode *node;

// 	if (*token == NULL)
// 		return (NULL);
// 	if (ft_strcmp((*token)->data, "<<") == 0)
// 	{
// 		node = io_here1(token);
// 		return (node);
// 	}
// 	if ((ft_strcmp((*token)->data, "<<-") == 0))
// 	{
// 		node = io_here2(token);
// 		return (node);
// 	}
// 	return (NULL);
// }
