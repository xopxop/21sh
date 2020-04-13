/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 11:28:21 by dthan             #+#    #+#             */
/*   Updated: 2020/04/13 11:28:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char *word_jump(char *input, int *tail)
{
	int head;
	char *str;

	head = *tail;
	while (input[*tail] && !is_separator_operator(input[*tail]))
	{
		if (input[*tail] == '"')
		{
			while (input[++(*tail)])
				if (input[*tail] == '"')
					break ;
		}
		(*tail)++;
	}
	str = ft_strndup(&input[head], *tail - head);
	return (str);
}

/*
**  Logic of the lexical_analysis_special:
**  - if char is Separator Op, and its next also, the syntax error will apeal
**    include return EXIT_FAILURE
**  - if char is Separator Op only, then make a token for this separator
**  - ofc at this stage, there is no Separator Op anymore, therefore, it is
**    safe to make a token for this word, this sub function will stop when
**	  it hit the Separator Op;
*/

int tokenizer_special(char *pre_token, t_token **lst_token)
{
	int i;
	t_token *node;
	char *temp;

	i = 0;
	while (pre_token[i])
	{
		if (is_separator_operator(pre_token[i]) && pre_token[i + 1] && \
			is_separator_operator(pre_token[i + 1])) // need to change the pre_token in error monitor
			return (error_monitor(SYNTAX_UNEXPECTED_TOKEN, pre_token, "'", NULL, EXIT_FAILURE, 0));
		else if (is_separator_operator(pre_token[i]))
		{
			temp = ft_strndup(&pre_token[i], 1);
			node = get_token(temp);
			push_node_into_ltoken(node, lst_token);
			free(temp);
			i++;
		}
		else
		{
			temp = word_jump(pre_token, &i);
			node = get_token(temp);
			push_node_into_ltoken(node, lst_token);
			free(temp);
		}
	}
	return (EXIT_SUCCESS);
}

void	tokenizer_normal(char *pre_token, t_token **lst_tokens)
{
	t_token *node;

	node = get_token(pre_token);
	push_node_into_ltoken(node, lst_tokens);
}
