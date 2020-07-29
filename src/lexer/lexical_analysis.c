/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 08:37:27 by dthan             #+#    #+#             */
/*   Updated: 2020/07/29 21:19:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char			*creat_non_quoted_string(char *input, char quote, size_t len)
{
	char		*start;
	char		*end;
	char		*new;
	int			i;
	int			j;

	start = ft_strchr(input, quote);
	end = ft_strrchr(input, quote);
	new = ft_strnew(len - 2);
	i = 0;
	j = 0;
	while (len > 0)
	{
		if (&input[j] != start && &input[j] != end)
			new[i++] = input[j];
		j++;
		len--;
	}
	ft_strdel(&input);
	return (new);
}

char			jump_single_or_double_quote(char *input, int *tail, char quote)
{
	while (input[++(*tail)])
		if (input[*tail] == quote)
			break ;
	return (quote);
}

static void 	word_jump(char *input, int *tail, t_token **lst_tokens)
{
	int head;
	t_token *node;
	char quote;

	quote = 0;
	head = *tail;
	while (input[*tail] && !ft_isspace(input[*tail]) && \
			!is_separator_operator(input, *tail) && \
			!is_redirection_operator(input, *tail)&& \
			!is_pipe_operator(input, *tail))
	{
		if (input[*tail] == '"')
			quote = jump_single_or_double_quote(input, tail, '"');
		else if (input[*tail] == '\'')
			quote = jump_single_or_double_quote(input, tail, '\'');
		/*if (input[*tail] == '"')
		{
			while (input[++(*tail)])
				if (input[*tail] == '"')
					break ;
		}*/
		(*tail)++;
	}
	node = get_token(ft_strndup(&input[head], *tail - head), quote);
	push_node_into_ltoken(input, head, node, lst_tokens);
}

static void	separator_operator_jump(char *input, int *tail, t_token **lst_tokens)
{
	int head;
	t_token *node;

	head = *tail;
	while (input[*tail] && is_separator_operator(input, *tail))
		(*tail)++;
	node = get_token(ft_strndup(&input[head], *tail - head), 0);
	push_node_into_ltoken(input, head, node, lst_tokens);
}

static void	redirection_operator_jump(char *input, int *tail, t_token **lst_tokens)
{
	int head;
	t_token *node;

	head = *tail;
	while (input[*tail] && is_redirection_operator(input, *tail))
		(*tail)++;
	node = get_token(ft_strndup(&input[head], *tail - head), 0);
	push_node_into_ltoken(input, head, node, lst_tokens);
}

static void pipe_operator_jump(char *input, int *tail, t_token **lst_tokens)
{
	int head;
	t_token *node;

	head = *tail;
	while (input[*tail] && is_pipe_operator(input, *tail))
		(*tail)++;
	node = get_token(ft_strndup(&input[head], *tail - head), 0);
	push_node_into_ltoken(input, head, node, lst_tokens);
}

int	check_syntax(t_token *lst_tokens)
{
	t_token *ptr;
	char buf[3];

	ptr = lst_tokens;
	ft_bzero(buf, 3);
	if (ptr && ptr->type == TOKEN_SEMI)
		return (error_monitor(SYNTAX_UNEXPECTED_TOKEN, ";", "'", NULL, EXIT_FAILURE, 0));
	while (ptr)
	{
		if (ptr->type == TOKEN_WORD && (is_separator_operator(ptr->data, 0) \
			|| is_redirection_operator(ptr->data, 0)))
			return (error_monitor(SYNTAX_UNEXPECTED_TOKEN, \
			ft_strncpy(buf, ptr->data, 2), "'", NULL, EXIT_FAILURE, 0));
		ptr = ptr->next;
	}
	return (EXIT_SUCCESS);
}

t_token	*lexical_analysis(char *input)
{
	t_token	*lst_tokens;
	int i;

	i = 0;
	lst_tokens = NULL;
	while (input[i])
	{
		if (is_separator_operator(input, i))
			separator_operator_jump(input, &i , &lst_tokens);
		else if (is_redirection_operator(input, i))
			redirection_operator_jump(input, &i , &lst_tokens);
		else if (is_pipe_operator(input, i))
			pipe_operator_jump(input, &i, &lst_tokens);
		else if (!ft_isspace(input[i]))
			word_jump(input, &i, &lst_tokens);
		else
			i++;
	}
	print_token(lst_tokens);
	if (check_syntax(lst_tokens) == EXIT_FAILURE)
		deltoken(&lst_tokens);
	print_token(lst_tokens);
	return (lst_tokens);
}
