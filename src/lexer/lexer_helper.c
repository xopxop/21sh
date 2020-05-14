/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 11:40:09 by dthan             #+#    #+#             */
/*   Updated: 2020/05/14 12:42:59 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void deltoken(t_token **lst)
{
	t_token *ptr;

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

int				is_hiphen(char *data)
{
	return (ft_strlen(data) == 1 && data[0] == '-');
}

void			get_additional_preceding_token_for_redirect
(t_token *tail_token, t_token *target_token)
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

void			change_token_type_for_redirection( \
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

void push_node_into_ltoken(char *input, int head, t_token *node, t_token **lst_tokens)
{
	t_token *p;

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

int is_separator_operator(char *input, int i)
{
	int front;

	front = i == 0 ? i : i - 1;
	if ((input[i] == '&' && input[front] != '>' && input[front] != '<')
		|| input[i] == ';') //ft_strchr(";", input[i]))
		return (1);
	return (0);
}

int	is_redirection_operator(char *input, int i)
{
	int front;

	front = i == 0 ? i : i - 1;
	if ((input[i] == '&' && (input[front] == '>' || input[front] == '<'))
		|| input[i] == '<' || input[i] == '>') //ft_strchr("><", input[i]))
		return (1);
	return (0);
}

char *is_pipe_operator(char *input, int i)
{
	return (ft_strchr("|", input[i]));
}

/*
** print token stream, for debugging purpose only
*/

void print_token(t_token *token)
{
	while (token)
	{
		ft_putchar('[');
		ft_putstr(token->data);
		ft_putstr("]->");
		token = token->next;
	}
	ft_putstr("NULL\n");
}

// void		ft_delete_dquote(char **tokens)     //OPEN LATER
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	while (tokens[++i])
// 	{
// 		j = -1;
// 		while (tokens[i][++j])
// 			if (tokens[i][j] == '"')
// 			{
// 				ft_strcpy(&tokens[i][j], &tokens[i][j + 1]);
// 				j = -1;
// 			}
// 	}
// }
