/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 07:06:11 by dthan             #+#    #+#             */
/*   Updated: 2020/08/02 18:15:42 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H
# include "token.h"

typedef enum
{
	AST_complete_command = (1 << 0),
	AST_list = (1 << 1),
	AST_and_or = (1 << 2),
	AST_pipeline = (1 << 3),
	AST_pipe_sequence = (1 << 4),
	AST_command = (1 << 5),
	AST_simple_command = (1 << 6),
	AST_cmd_name = (1 << 7),
	AST_cmd_prefix = (1 << 8),
	AST_cmd_suffix = (1 << 9),
	AST_io_redirect = (1 << 11),
	AST_io_file = (1 << 12),
	AST_filename = (1 << 13),
	AST_io_fd = (1 << 14),
	AST_WORD = (1 << 10),
}	t_astnode_type;

typedef struct			s_astnode
{
	int					type;
	char				*data;
	struct s_astnode	*left;
	struct s_astnode	*right;
}						t_astnode;

t_astnode				*complete_command(t_token **token);
t_astnode				*list(t_token **token);
t_astnode				*and_or(t_token **token);
t_astnode				*pipeline(t_token **token);
t_astnode				*pipe_sequence(t_token **token);
t_astnode				*command(t_token **token);
t_astnode				*compound_command(t_token **token);
t_astnode				*subshell(t_token **token);
t_astnode				*compound_list(t_token **token);
t_astnode				*term(t_token **token);
t_astnode				*for_clause(t_token **token);
t_astnode				*name(t_token **token);
t_astnode				*in(t_token **token);
t_astnode				*wordlist(t_token **token);
t_astnode				*case_clause(t_token **token);
t_astnode				*case_list_ns(t_token **token);
t_astnode				*case_list(t_token **token);
t_astnode				*case_item_ns(t_token **token);
t_astnode				*case_item(t_token **token);
t_astnode				*pattern(t_token **token);
t_astnode				*if_clause(t_token **token);
t_astnode				*else_part(t_token **token);
t_astnode				*while_clause(t_token **token);
t_astnode				*until_clause(t_token **token);
t_astnode				*function_definition(t_token **token);
t_astnode				*function_body(t_token **token);
t_astnode				*fname(t_token **token);
t_astnode				*brace_group(t_token **token);
t_astnode				*do_group(t_token **token);
t_astnode				*simple_command(t_token **token);
t_astnode				*cmd_name(t_token **token);
t_astnode				*cmd_prefix(t_token **token);
t_astnode				*cmd_suffix(t_token **token);
t_astnode				*redirect_list(t_token **token);
t_astnode				*io_redirect(t_token **token);
t_astnode				*io_file(t_token **token);
t_astnode				*filename(t_token **token);
t_astnode				*io_here(t_token **token);
t_astnode				*here_end(t_token **token);
t_astnode				*newline_list(t_token **token);
t_astnode				*linebreak(t_token **token);
t_astnode				*separator_op(t_token **token);
t_astnode				*separotor(t_token **token);
t_astnode				*sequential_sep(t_token **token);
t_astnode				*word(t_token **token);

t_astnode				*io_file1(t_token **token);
t_astnode				*io_file2(t_token **token);
t_astnode				*io_file3(t_token **token);
t_astnode				*io_file4(t_token **token);
t_astnode				*io_file5(t_token **token);
t_astnode				*io_file6(t_token **token);

t_astnode				*build_node(t_astnode_type type);

void					ft_delast(t_astnode *node);
void					clear_ast(t_astnode *ast);

/*
** debugging
** void printBinaryTree(t_astnode * t);
*/

#endif
