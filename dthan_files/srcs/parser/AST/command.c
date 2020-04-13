/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 08:45:09 by dthan             #+#    #+#             */
/*   Updated: 2020/04/11 08:45:10 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/ast.h"

/*
** command : simple_command
**         | compound_command					//not
**         | compound_command redirect_list		//not
**         | function_definition				//not
*/

t_astnode *command(t_token **token)
{
	t_astnode *node;
	t_astnode *childnode;

	if ((childnode = simple_command(token)) == NULL)
		return (NULL);
	node = build_node(AST_command);
	node->data = ft_strdup("command");
	node->left = childnode;
	node->right = NULL;
	return(node);	
}
