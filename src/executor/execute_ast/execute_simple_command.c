/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:39:32 by dthan             #+#    #+#             */
/*   Updated: 2020/08/01 23:30:39 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void exchange_src_des_for_less(t_exe *exe)
{
	char *temp;
	t_redirect *trav;

	trav = exe->redi;
	while(trav)
	{
		if (ft_strequ(trav->redirect_op, "<") || \
			ft_strequ(trav->redirect_op, "<<") || \
			ft_strequ(trav->redirect_op, "<&"))
			{
				temp = trav->redirect_des;
				trav->redirect_des = trav->redirect_src;
				trav->redirect_src = temp;
			}
		trav = trav->next;
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
		ptr = exe->redi;
		exe->redi = exe->redi->next;
		free(ptr);
	}
	free(exe->av);
}

static void clear_redi(t_exe *exe)
{
	exe->redi = NULL;
}

void execute_simple_command(t_astnode *ast, t_exe *exe)
{
	if (ast->type == AST_simple_command)
	{
		if (exe->redi)
			clear_redi(exe);
		get_av_cmd_name(ast->left, exe);
		get_av_cmd_suffix(ast->right, exe, 0);
		exchange_src_des_for_less(exe);
	}
	else
		get_av_cmd_name(ast, exe);
	run(exe);
}
