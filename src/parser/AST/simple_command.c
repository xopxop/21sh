/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 08:49:46 by dthan             #+#    #+#             */
/*   Updated: 2020/04/11 08:49:50 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

/*
** simple_command : cmd_prefix cmd_word cmd_suffix		//not
**                | cmd_prefix cmd_word					//not
**                | cmd_prefix							//not
**                | cmd_name cmd_suffix				1
**                | cmd_name						2
*/

t_astnode *simple_command2(t_token **token)
{
	return (cmd_name(token));
}

t_astnode *simple_command1(t_token **token)
{
	t_astnode *node;
	t_astnode *lnode;
	t_astnode *rnode;

	if ((lnode = cmd_name(token)) == NULL)
		return (NULL);
	if ((rnode = cmd_suffix(token)) == NULL)
	{
		ft_delast(lnode);
		return (NULL);
	}
	node = build_node(AST_simple_command);
	node->left = lnode;
	node->right = rnode;
	return (node);
}

t_astnode *simple_command(t_token **token)
{
	t_astnode	*node;
	t_token		*reset;

	reset = *token;
	if ((node = simple_command1(token)) != NULL)
		return (node);
	*token = reset;
	if ((node = simple_command2(token)) != NULL)
		return (node);
	return (NULL);
}
