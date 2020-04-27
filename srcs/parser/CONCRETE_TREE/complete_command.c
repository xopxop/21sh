/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 11:17:31 by dthan             #+#    #+#             */
/*   Updated: 2020/04/07 11:17:32 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

/*
** complete_command : list separator	1
**                	| list				2
*/

t_astnode	*complete_command2(t_token **token)
{
	t_astnode *node;
	t_astnode *childnode;

	if ((childnode = list(token)) == NULL)
		return (NULL);
	node = build_node(AST_complete_command);
	node->data = ft_strdup("complete_command2");
	node->left = childnode;
	node->right = NULL;
	return (node);
}

t_astnode	*complete_command1(t_token **token)
{
	t_astnode *node;
	t_astnode *lnode;

	if ((lnode = list(token)) == NULL)
		return (NULL);
	if (!*token || ((ft_strcmp((*token)->data, ";") != 0) \
				&& (ft_strcmp((*token)->data, "&") != 0)))
	{	
		ft_delast(lnode);
		return (NULL);
	}
	*token = (*token)->next;
	node = build_node(AST_complete_command);
	node->left = lnode;
	node->data = ft_strdup("complete_command1");
	return (node);
}

t_astnode	*complete_command(t_token **token)
{
	t_astnode	*node;
	t_token		*reset;

	reset = *token;
	if ((node = complete_command1(token)) != NULL)
		return (node);
	*token = reset;
	if ((node = complete_command2(token)) != NULL)
		return (node);
	return (NULL);
}