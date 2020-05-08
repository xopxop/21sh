/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:39:32 by dthan             #+#    #+#             */
/*   Updated: 2020/05/08 02:26:21 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void exchange_src_des_for_less(t_exe *exe)
{
	char *temp;
	t_redirect *traverse;

	traverse = exe->redi;
	while(traverse)
	{
		if (ft_strequ(traverse->redirect_op, "<") || \
			ft_strequ(traverse->redirect_op, "<<") || \
			ft_strequ(traverse->redirect_op, "<&"))
			{
				temp = traverse->redirect_des;
				traverse->redirect_des = traverse->redirect_src;
				traverse->redirect_src = temp;
			}
		traverse = traverse->next;
	}
}

void clear_ast(t_astnode *ast)
{
	if (ast->left)
		clear_ast(ast->left);
	if (ast->right)
		clear_ast(ast->right);
	ft_delast(ast);
}

void clear_exe(t_exe *exe)
{
	void *ptr;

	while (exe->heredoc)
	{
		ft_strdel(&exe->heredoc->heredoc);
		ptr = exe->heredoc;
		exe->heredoc = exe->heredoc->next;
		free(ptr);
	}
	while (exe->redi)
	{
		ft_strdel(&exe->redi->redirect_op);
		ft_strdel(&exe->redi->redirect_src);
		ft_strdel(&exe->redi->redirect_des);
		ptr = exe->redi;
		exe->redi = exe->redi->next;
		free(ptr);
	}
	ft_strlst_del(&exe->av, exe->ac + 1);
}

void execute_simple_command(t_astnode *ast, t_exe *exe)
{
	if (ast->type == AST_simple_command)
	{
		get_av_cmd_name(ast->left, exe);
		get_av_cmd_suffix(ast->right, exe, 0);
		exchange_src_des_for_less(exe);
	}
	else
		get_av_cmd_name(ast, exe);
	clear_ast(ast);
	run(exe);
	clear_exe(exe);
// should be added later
}
