/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 09:17:44 by dthan             #+#    #+#             */
/*   Updated: 2020/05/05 23:32:54 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

/*t_astnode *word(t_token **token, int opt)
{
	t_astnode *node;

	(void)opt;
	if (*token == NULL)
		return (NULL);
	if ((*token)->type != TOKEN_WORD)
		return (NULL);
	node = build_node(AST_WORD);
	node->data = ft_strdup((*token)->data);
	node->left = NULL;
	node->right = NULL;
	*token = (*token)->next;
	return (node);
}
*/
t_astnode *io_number(t_token **token)
{
	t_astnode *node;

	if (*token == NULL)
		return(NULL);
	node = build_node(AST_io_fd);
	node->data = ft_strdup((*token)->data);
	node->left = NULL;
	node->right = NULL;
	*token = (*token)->next;
	return (node);
}

t_astnode *word(t_token **token)
{
	t_astnode *node;

	if (*token == NULL)
		return (NULL);
//	if ((*token)->type == TOKEN_IO_NUMBER || \
//		((*token)->type == TOKEN_HIPHEN && opt == TOKEN_SPECIFIER_HIPHEN))
//		return (io_number_or_hiphen(token));
	if ((*token)->type == TOKEN_IO_NUMBER)
		return (io_number(token));
	node = build_node(AST_WORD);
	node->data = ft_strdup((*token)->data);
	node->left = NULL;
	node->right = NULL;
	*token = (*token)->next;
	return (node);
}