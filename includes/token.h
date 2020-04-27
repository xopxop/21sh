/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 07:58:26 by dthan             #+#    #+#             */
/*   Updated: 2020/04/07 07:58:27 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum
{
	TOKEN_WORD,
	TOKEN_ASSIGNMENT_WORD,
	TOKEN_NAME,
	TOKEN_NEWLINE,
	TOKEN_IO_NUMBER,
	TOKEN_AND_IF,
	TOKEN_OR_IF,
	TOKEN_DSEMI,
	TOKEN_DLESS,
	TOKEN_DGREAT,
	TOKEN_LESSAND,
	TOKEN_GREATAND,
	TOKEN_LESSGREAT,
	TOKEN_DLESSDASH,
	TOKEN_CLOBBER,
	// TOKEN_If,
	// TOKEN_Then,
	// TOKEN_Else,
	// TOKEN_Elif,
	// TOKEN_Fi,
	// TOKEN_Do,
	// TOKEN_Done,
	// TOKEN_Case,
	// TOKEN_Esac,
	// TOKEN_While,
	// TOKEN_Until,
	// TOKEN_For,
	// TOKEN_Lbrace,
	// TOKEN_Rbrace,
	// TOKEN_Bang,
	// TOKEN_In,
	//add new token from here
	TOKEN_OR,		// '|'
	TOKEN_SEMI,		// ';'
	TOKEN_AND,		// '&'
	TOKEN_GREAT,	// '>'
	TOKEN_LESS,		// '<'
}	t_token_type;

typedef struct			s_token
{
	char				*data;
	t_token_type		type;
	struct s_token		*next;
}						t_token;

t_token	*get_token(char *input);
void	deltoken(t_token **lst);
void	push_node_into_ltoken(t_token *node, t_token **head);
void	print_token(t_token *token);
void	ft_delete_dquote(char **tokens);

int is_separator_operator(char c);
int	is_redirection_operator(char c);

#endif
