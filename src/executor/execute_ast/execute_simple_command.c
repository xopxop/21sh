/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:39:32 by dthan             #+#    #+#             */
/*   Updated: 2020/04/27 13:28:36 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_simple_command(t_astnode *ast, t_exe *exe)
{
	if (ast->type == AST_simple_command)
	{
		get_av_cmd_name(ast->left, exe);
		get_av_cmd_suffix(ast->right, exe);
	}
	else
		get_av_cmd_name(ast, exe);
	run(exe);
	// reset redirection
	if (ft_strequ(exe->redirect_op, "<<"))
		exe->heredoc =  exe->heredoc->next;
	exe->redirect_op =  NULL;
	exe->redirect_des = NULL;
	exe->redirect_src = NULL;
}
