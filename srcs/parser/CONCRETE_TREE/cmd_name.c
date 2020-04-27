/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 08:58:06 by dthan             #+#    #+#             */
/*   Updated: 2020/04/11 08:58:09 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

/*
** cmd_name : WORD     //Apply rule 7a
*/

t_astnode *cmd_name(t_token **token)
{
	t_astnode *node;
	t_astnode *childnode;

	if ((childnode = word(token)) == NULL)
		return (NULL);
	node = build_node(AST_cmd_name);
	node->data = ft_strdup("cmd_name");
	node->left = childnode;
	node->right = NULL;
	return (node);
}
