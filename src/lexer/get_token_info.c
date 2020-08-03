/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 11:32:27 by dthan             #+#    #+#             */
/*   Updated: 2020/08/02 15:19:06 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_token_type	get_token_type2(char *input)
{
	if (!ft_strcmp(input, ">|"))
		return (TOKEN_CLOBBER);
	else if (!ft_strcmp(input, "|"))
		return (TOKEN_OR);
	else if (!ft_strcmp(input, ";"))
		return (TOKEN_SEMI);
	else if (!ft_strcmp(input, "&"))
		return (TOKEN_AND);
	else if (!ft_strcmp(input, ">"))
		return (TOKEN_GREAT);
	else if (ft_strequ(input, "<"))
		return (TOKEN_LESS);
	return (TOKEN_WORD);
}

static	t_token_type	get_token_type1(char *input)
{
	if (!ft_strcmp(input, "||"))
		return (TOKEN_OR_IF);
	else if (!ft_strcmp(input, "<<"))
		return (TOKEN_DLESS);
	else if (!ft_strcmp(input, ">>"))
		return (TOKEN_DGREAT);
	else if (!ft_strcmp(input, "<&"))
		return (TOKEN_LESSAND);
	else if (!ft_strcmp(input, ">&"))
		return (TOKEN_GREATAND);
	else if (!ft_strcmp(input, "<>"))
		return (TOKEN_LESSGREAT);
	else if (!ft_strcmp(input, "<<-"))
		return (TOKEN_DLESSDASH);
	else
		return (get_token_type2(input));
}

t_token					*get_token(char *input, char quote)
{
	t_token				*node;

	node = (t_token*)malloc(sizeof(t_token));
	node->type = get_token_type1(input);
	if (quote)
		node->data = creat_non_quoted_string(input, quote, ft_strlen(input));
	else
		node->data = input;
	node->next = NULL;
	return (node);
}
