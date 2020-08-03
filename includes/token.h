/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 07:58:26 by dthan             #+#    #+#             */
/*   Updated: 2020/08/02 18:06:53 by tango            ###   ########.fr       */
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
	TOKEN_OR,
	TOKEN_SEMI,
	TOKEN_AND,
	TOKEN_GREAT,
	TOKEN_DGREAT,
	TOKEN_LESS,
	TOKEN_DLESS,
	TOKEN_LESSAND,
	TOKEN_GREATAND,
	TOKEN_LESSGREAT,
	TOKEN_DLESSDASH,
	TOKEN_CLOBBER,
}	t_token_type;

typedef struct			s_token
{
	char				*data;
	t_token_type		type;
	struct s_token		*next;
}						t_token;

t_token					*get_token(char *input, char quote);
void					deltoken(t_token **lst);
void					print_token(t_token *token);
void					ft_delete_dquote(char **tokens);
int						is_separator_operator(char *input, int i);
int						is_redirection_operator(char *input, int i);
char					*is_pipe_operator(char *input, int i);
void					interpret_tild(char **str);
void					interpret_dollar(t_token *node);
int						check_syntax(t_token *lst_tokens);
char					*creat_non_quoted_string(char *input,\
		char quote, size_t len);
char					jump_single_or_double_quote(char *input,\
		int *tail, char quote);
void					push_node_into_ltoken(char *input,\
		int head, t_token *node, t_token **lst_tokens);

#endif
