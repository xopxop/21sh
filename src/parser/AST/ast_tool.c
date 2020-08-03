/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 07:29:09 by dthan             #+#    #+#             */
/*   Updated: 2020/08/02 15:52:53 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_astnode		*build_node(t_astnode_type type)
{
	t_astnode	*node;

	node = (t_astnode*)malloc(sizeof(t_astnode));
	node->data = NULL;
	node->type = type;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void			ft_delast(t_astnode *node)
{
	ft_strdel(&(node->data));
	free(node);
}
