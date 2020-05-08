/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:24:09 by dthan             #+#    #+#             */
/*   Updated: 2020/05/07 20:36:40 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ast.h"

void	clear_token(t_token *token)
{
	t_token *temp;

	while (token)
	{
		ft_strdel(&token->data);
		temp = token;
		token = token->next;
		free(temp);
	}
}

static t_astnode *build_ast(t_token *token)
{
	return (complete_command(&token));
}

t_astnode	*syntax_analysis(t_token *token)
{
	t_astnode *abstract_syntax_tree;

	if ((abstract_syntax_tree = build_ast(token)) == NULL)
	{
		clear_token(token);
		return(NULL);
	}
	clear_token(token);
	return (abstract_syntax_tree);
}
