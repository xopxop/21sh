/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:24:09 by dthan             #+#    #+#             */
/*   Updated: 2020/08/02 16:05:22 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_astnode	*build_ast(t_token *token)
{
	return (complete_command(&token));
}

t_astnode			*syntax_analysis(t_token *token)
{
	t_astnode		*abstract_syntax_tree;

	if ((abstract_syntax_tree = build_ast(token)) == NULL)
	{
		return (NULL);
	}
	return (abstract_syntax_tree);
}
