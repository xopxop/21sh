/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 07:29:09 by dthan             #+#    #+#             */
/*   Updated: 2020/04/11 07:29:09 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

t_astnode	*build_node(t_astnode_type type)
{
	t_astnode *node;

	node = (t_astnode*)malloc(sizeof(t_astnode)); //need eermem
	node->data = NULL,
	node->type = type;
	node->right = NULL;
	node->right = NULL;
	return (node);
}


void ft_delast(t_astnode *node)
{
	free(node->data);
	free(node);
}