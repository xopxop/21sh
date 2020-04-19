/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_space_destroyer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 11:43:21 by dthan             #+#    #+#             */
/*   Updated: 2020/04/20 01:10:21 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_single_pretoken(char *input, int *tail)
{
	char	*str;
	int		head;

	head = *tail;
	while (input[(*tail)] && !ft_isspace(input[*tail]))
	{
		if (input[*tail] == '"')
		{
			while (input[++(*tail)])
				if (input[*tail] == '"')
					break ;
		}
		(*tail)++;
	}
	if (*tail <= head)
		return (NULL);
	str = ft_strndup(&input[head], *tail - head + 1);
	while (input[(*tail)] && ft_isspace(input[*tail]))
		(*tail)++;
	return (str);
}

static void	jump_dquote(char *str, int *i, int *inside_dquote)
{
	while (str[*i] != '"')
		(*i)++;
	(*i)++;
	*inside_dquote = 0;
}

static void	jump_pretoken(char *str, int *i)  // we can combine the word_jump in tokenizer.c file
{
	int inside_dquote;

	inside_dquote = 0;
	while (str[*i] && !ft_isspace(str[*i]))
	{
		if (str[*i] == '"')
		{
			inside_dquote = 1;
			(*i)++;
			jump_dquote(str, i, &inside_dquote);
		}
		else
			(*i)++;
	}
}

static int	get_nb_of_pretokens(char *input)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (input[i])
	{
		if (!ft_isspace(input[i]))
		{
			size++;
			jump_pretoken(input, &i);
		}
		else
			i++;
	}
	return (size);
}

char	**split_input(char *input)
{
	char	**tokens;
	int		size;
	int		i;
	int		pos_input;

	i = -1;
	pos_input = 0;
	size = get_nb_of_pretokens(input);
	tokens = (char**)malloc(sizeof(char*) * (size + 1)); //error mem
	while (++i < size)
		tokens[i] = get_single_pretoken(input, &pos_input);
	tokens[i] = NULL;
	return (tokens);
}
