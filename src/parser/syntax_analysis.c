/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:24:09 by dthan             #+#    #+#             */
/*   Updated: 2020/05/10 19:46:11 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ast.h"



static t_astnode *build_ast(t_token *token)
{
	return (complete_command(&token));
}

t_astnode	*syntax_analysis(t_token *token)
{
	t_astnode *abstract_syntax_tree;

	if ((abstract_syntax_tree = build_ast(token)) == NULL)
	{
		return(NULL);
	}
	return (abstract_syntax_tree);
}
