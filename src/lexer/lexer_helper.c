/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 11:40:09 by dthan             #+#    #+#             */
/*   Updated: 2020/04/13 11:40:13 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void deltoken(t_token *lst)
{
	t_token *ptr;

	while (lst)
	{
		ptr = lst;
		lst = lst->next;
		free(ptr->data);
		free(ptr);
	}
}

void push_node_into_ltoken(t_token *node, t_token **head)
{
	t_token *p;

	if (*head == NULL)
		*head = node;
	else
	{
		p = *head;
		while (p->next)
			p = p->next;
		p->next = node;
	}
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
		ft_putstr("]-->");
		token = token->next;
	}
	ft_putstr("NULL\n");
}

int	pre_token_contains_separator_operator(char *pre_token)
{
	int i;

	i = -1;
	while(pre_token[++i])
		if (is_separator_operator(pre_token[i]))
			return (1);
	return (0);
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
