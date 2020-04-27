/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 08:32:29 by dthan             #+#    #+#             */
/*   Updated: 2020/04/11 08:32:30 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

/*
** pipeline :      pipe_sequence
**          | Bang pipe_sequence    //not
*/

t_astnode *pipeline(t_token **token)
{
	t_astnode *node;
	t_astnode *childnode;

	if ((childnode = pipe_sequence(token)) == NULL)
		return (NULL);
	node = build_node(AST_pipeline);
	node->data = ft_strdup("pipeline");
	node->left = childnode;
	node->right = NULL;
	return (node);
}
