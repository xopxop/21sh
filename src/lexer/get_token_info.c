/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 11:32:27 by dthan             #+#    #+#             */
/*   Updated: 2020/04/13 11:32:30 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_token_type	get_token_type(char *input)
{
	// if (!ft_strcmp(input, "&&"))		//not in use
	// 	return (TOKEN_AND_IF);
	if (!ft_strcmp(input, "||"))
		return (TOKEN_OR_IF);
	// if (!ft_strcmp(input, ";;"))		//not in use
	// 	return (TOKEN_DSEMI);
	if (!ft_strcmp(input, "<<"))
		return (TOKEN_DLESS);
	if (!ft_strcmp(input, ">>"))
		return (TOKEN_DGREAT);
	if (!ft_strcmp(input, "<&"))
		return (TOKEN_LESSAND);
	if (!ft_strcmp(input, ">&"))
		return (TOKEN_GREATAND);
	if (!ft_strcmp(input, "<>"))
		return (TOKEN_LESSGREAT);
	if (!ft_strcmp(input, "<<-"))
		return (TOKEN_DLESSDASH);
	if (!ft_strcmp(input, ">|"))
		return (TOKEN_CLOBBER);
	// if (!ft_strcmp(input, "if")) //there must be sth strange here because what abt ls if? , it is revered word
	// 	return (TOKEN_If);
	// if (!ft_strcmp(input, "then"))
	// 	return (TOKEN_Then);
	// if (!ft_strcmp(input, "else"))
	// 	return (TOKEN_Else);
	// if (!ft_strcmp(input, "fi"))
	// 	return (TOKEN_Fi);
	// if (!ft_strcmp(input, "do"))
	// 	return (TOKEN_Do);
	// if (!ft_strcmp(input, "done"))
	// 	return (TOKEN_Done);
	// if (!ft_strcmp(input, "case"))
	// 	return (TOKEN_Case);
	// if (!ft_strcmp(input, "esac"))
	// 	return (TOKEN_Esac);
	// if (!ft_strcmp(input, "while"))
	// 	return (TOKEN_While);
	// if (!ft_strcmp(input, "until"))
	// 	return (TOKEN_Until);
	// if (!ft_strcmp(input, "for"))
	// 	return (TOKEN_For);
	// if (!ft_strcmp(input, "{"))
	// 	return (TOKEN_Lbrace);
	// if (!ft_strcmp(input, "}"))
	// 	return (TOKEN_Rbrace);
	// if (!ft_strcmp(input, "!"))
	// 	return (TOKEN_Bang);
	// if (!ft_strcmp(input, "in"))
	// 	return (TOKEN_In);
	if (!ft_strcmp(input, "|")) // add new token here
		return (TOKEN_OR);
	if (!ft_strcmp(input, ";"))
		return (TOKEN_SEMI);
	if (!ft_strcmp(input, "&"))
		return (TOKEN_AND);
	if (!ft_strcmp(input, ">"))
		return (TOKEN_GREAT);
	if (ft_strequ(input, "<"))
		return (TOKEN_LESS);
	return (TOKEN_WORD); // also token assignment word, name, new_line, IO_number
}

// t_token			*get_token(char *input)
// {
// 	t_token *node;

// 	node = (t_token*)malloc(sizeof(t_token));
// 	node->data = ft_strdup(input);
// 	node->type = get_token_type(input);
// 	node->next = NULL;
// 	return (node);
// }

t_token			*get_token(char *input)
{
	t_token *node;

	node = (t_token*)malloc(sizeof(t_token));
	node->data = input;
	node->type = get_token_type(input);
	node->next = NULL;
	return (node);
}
