/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:39:32 by dthan             #+#    #+#             */
/*   Updated: 2020/05/04 23:34:19 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void exchange_src_des_for_less(t_exe *exe)
{
	char *temp;
	int nb;

	nb = -1;
	while (++nb < REDI_MAX)
	{
		if (ft_strequ(exe->redirect_op[nb], "<"))
		{
			temp = exe->redirect_des[nb];
			exe->redirect_des[nb] = exe->redirect_src[nb];
			exe->redirect_src[nb] = temp;
		}
	}
}

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

void execute_simple_command(t_astnode *ast, t_exe *exe)
{
	int redirect_level;

	if (ast->type == AST_simple_command)
	{
		redirect_level = 0;
		init_redirect_elements(exe);
		get_av_cmd_name(ast->left, exe);
		get_av_cmd_suffix(ast->right, exe, 0, &redirect_level);
		exchange_src_des_for_less(exe);
	}
	else
		get_av_cmd_name(ast, exe);
	run(exe);
	// reset redirection
	/*if (ft_strequ(exe->redirect_op, "<<"))
		exe->heredoc =  exe->heredoc->next;
	exe->redirect_op =  NULL;
	exe->redirect_des = NULL;
	exe->redirect_src = NULL;*/
}
