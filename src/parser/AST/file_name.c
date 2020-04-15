/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 10:13:47 by dthan             #+#    #+#             */
/*   Updated: 2020/04/11 10:13:49 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

// t_astnode	*filename(t_token **token)
// {
// 	t_astnode *node;

// 	if (*token == NULL)
// 		return (NULL);
// 	if ((*token)->type != TOKEN_WORD)
// 		return (NULL);
// 	node = build_node(AST_filename);
// 	node->data = ft_strdup((*token)->data);
// 	node->left = NULL;
// 	node->right = NULL;
// 	*token = (*token)->next;
// 	return (node);
// }
