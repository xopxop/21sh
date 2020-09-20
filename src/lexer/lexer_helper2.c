/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 03:00:12 by tango             #+#    #+#             */
/*   Updated: 2020/08/05 05:42:28 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			deltoken(t_token **lst)
{
	t_token		*ptr;

	while (*lst)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		ft_strdel(&ptr->data);
		free(ptr);
	}
}

int				is_made_of_digits(char *data)
{
	int			i;

	i = -1;
	while (data[++i])
		if (!ft_isdigit(data[i]))
			return (0);
	return (1);
}

void			get_additional_preceding_token_for_redirect(\
		t_token *tail_token, t_token *target_token)
{
	t_token		*additional_token;

	additional_token = (t_token*)malloc(sizeof(t_token));
	additional_token->type = TOKEN_IO_NUMBER;
	additional_token->next = tail_token;
	if (ft_strequ(tail_token->data, "<") || ft_strequ(tail_token->data, "<<") \
		|| ft_strequ(tail_token->data, "<&"))
		additional_token->data = ft_strdup("0");
	else
		additional_token->data = ft_strdup("1");
	target_token->next = additional_token;
}

void			change_token_type_for_redirection(\
	char *input, int head, t_token **lst_tokens)
{
	t_token		*tail_token;
	t_token		*target_token;

	tail_token = lst_tokens[0];
	target_token = lst_tokens[0];
	while (tail_token->next)
		tail_token = tail_token->next;
	if (target_token->next)
		while (target_token->next->next)
			target_token = target_token->next;
	if (tail_token->type >= TOKEN_GREAT && !ft_isspace(input[head - 1]) && \
		is_made_of_digits(target_token->data))
		target_token->type = TOKEN_IO_NUMBER;
	else if (tail_token->type >= TOKEN_GREAT)
		get_additional_preceding_token_for_redirect(tail_token, target_token);
}

void			push_node_into_ltoken(char *input, \
		int head, t_token *node, t_token **lst_tokens)
{
	t_token		*p;

	if (*lst_tokens == NULL)
		*lst_tokens = node;
	else
	{
		p = *lst_tokens;
		while (p->next)
			p = p->next;
		p->next = node;
	}
	if (node->type == TOKEN_WORD)
	{
		interpret_tild(&node->data);
		interpret_dollar(node);
	}
	change_token_type_for_redirection(input, head, lst_tokens);
}
