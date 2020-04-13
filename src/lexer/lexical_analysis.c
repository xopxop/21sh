/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 08:37:27 by dthan             #+#    #+#             */
/*   Updated: 2020/04/09 08:37:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Lexer will do:
** 1. remove all the white space and will produce a list of pre_tokens,
**    to prepare for screening 2nd time
** 2. each pre_tokens will fo through the 2nd screening, this step will be
**    called as tokenizer, it will take care of the case if the token is
**    not separated each other with the white space
**    - lexical_analysis_normal will be activated when the pre_token does 
**      not contain separator operator (;&)
**    - lexical_analysis_special will be activated when the pre_token 
**      contains the separator operator. When there is syntax error appeals
**      it will delete the list of token and the pre_tokens array
*/

t_token	*lexical_analysis(char *input)
{
	char	**pre_tokens;
	t_token	*lst_tokens;
	int		i;

	i = -1;
	lst_tokens = NULL;
	pre_tokens = split_input(input);
	while (pre_tokens[++i])
		if (!pre_token_contains_separator_operator(pre_tokens[i]))
			tokenizer_normal(pre_tokens[i], &lst_tokens);
		else if (tokenizer_special(pre_tokens[i], &lst_tokens) == EXIT_FAILURE)
		{
			ft_arraydel(pre_tokens);
			deltoken(lst_tokens);
			return (NULL);
		}	
	print_token(lst_tokens);  //for debugging
	ft_arraydel(pre_tokens);
	return (lst_tokens);
}
