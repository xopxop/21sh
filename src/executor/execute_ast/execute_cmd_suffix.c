/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:14:52 by dthan             #+#    #+#             */
/*   Updated: 2020/05/04 23:58:31 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	get_av_cmd_suffix(t_astnode *ast, t_exe *exe, int opt, int *redi_lv)
{
	if (ast->type == AST_WORD && opt == 0)
	{
		exe->ac++;
		exe->av[exe->ac - 1] = ast->data;
		exe->av[exe->ac] = NULL;
	}
	else if (ast->type == AST_cmd_suffix)
	{
		get_av_cmd_suffix(ast->left, exe, 0, redi_lv);
		get_av_cmd_suffix(ast->right, exe, 0, redi_lv);
	}
	else if (ast->type == AST_io_redirect)
	{
		exe->redirect_src[*redi_lv] = ast->data;
		get_av_cmd_suffix(ast->right, exe, 0, redi_lv);
	}
	else if (ast->type == AST_io_file)
	{
		exe->redirect_op[*redi_lv] = ast->data;
		get_av_cmd_suffix(ast->left, exe, 1, redi_lv);
	}
	else if (opt)
		exe->redirect_des[(*redi_lv)++] = ast->data;
}