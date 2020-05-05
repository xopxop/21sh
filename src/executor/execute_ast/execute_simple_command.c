/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:39:32 by dthan             #+#    #+#             */
/*   Updated: 2020/05/05 23:08:50 by ihwang           ###   ########.fr       */
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
			ft_strequ(traverse->redirect_op, "<<"))
			{
				temp = traverse->redirect_des;
				traverse->redirect_des = traverse->redirect_src;
				traverse->redirect_src = temp;
			}
		traverse = traverse->next;
	}
}

/*
static void init_redirect_elements(t_exe *exe)
{
	int redi_max;

	redi_max = REDI_MAX;
	exe->redirect_op = (char**)malloc(sizeof(char*) * redi_max);
	exe->redirect_des = (char**)malloc(sizeof(char*) * redi_max);
	exe->redirect_src = (char**)malloc(sizeof(char*) * redi_max);
	while (--redi_max >= 0)
	{
		exe->redirect_op[redi_max] = NULL;
		exe->redirect_des[redi_max] = NULL;
		exe->redirect_src[redi_max] = NULL;
	}
}
*/

/*
void clear_exe(t_exe *exe)
{
	free(exe->redirect_op);
	free(exe->redirect_des);
	free(exe->redirect_src);
	ft_strdel(&exe->heredoc->heredoc);
	if (exe->heredoc)
		free(exe->heredoc);
}
*/

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
	run(exe);
//	clear_exe(exe);
// should be added later
}
