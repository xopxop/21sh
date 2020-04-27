/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 09:24:37 by dthan             #+#    #+#             */
/*   Updated: 2020/04/11 09:24:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

/*
** io_redirect:           io_file
**            | IO_NUMBER io_file
**            |           io_here
**            | IO_NUMBER io_here
*/

// t_astnode *io_redirect1(t_token **token)
// {
// 	t_astnode *node;
// 	t_astnode *childnode;

// 	if(*token == NULL)
// 		return (NULL);
// 	if ((*token)->type == TOKEN_IO_NUMBER)
// 		return (NULL);
// 	if ((childnode = io_file(token)) == NULL)
// 		return (NULL);
// 	node = build_node(AST_io_redirect);
// 	node->data = ft_strdup((*token)->data);
// 	node->left = childnode;
// 	return (node);
// }

t_astnode *io_redirect2(t_token **token)
{
	return (io_file(token));
}



// t_astnode *io_redirect3(t_token **token)
// {
// 	return (io_here(token));
// }	

// t_astnode *io_redirect4(t_token **token)
// {
// 	t_astnode *node;
// 	t_astnode *childnode;

// 	if(*token == NULL)
// 		return (NULL);
// 	if ((*token)->type != TOKEN_IO_NUMBER)
// 		return (NULL);
// 	*token = (*token)->next;
// 	if ((childnode = io_here(token)) == NULL)
// 		return (NULL);
// 	node = build_node(AST_io_redirect);
// 	node->data =ft_strdup((*token)->data);
// 	node->left = childnode;
// 	return (node);
// }

t_astnode *io_redirect(t_token **token)
{
	t_astnode *node;

	// if ((node = io_redirect1(token)) != NULL)
	// 	return (node);
	if ((node = io_redirect2(token)) != NULL)
		return (node);
	// if ((node = io_redirect3(token)) != NULL)
	// 	return (node);
	// if ((node = io_redirect4(token)) != NULL)
	// 	return (node);
	return (NULL);
}
