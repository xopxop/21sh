/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:14:52 by dthan             #+#    #+#             */
/*   Updated: 2020/04/17 11:14:54 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	get_av_cmd_suffix(t_astnode *ast, t_exe *exe)
{
	if (ast->type == AST_WORD)
	{
		exe->ac++;
		exe->av[exe->ac - 1] = ast->data;
		exe->av[exe->ac] = NULL;
	}
	else if (ast->type == AST_cmd_suffix)
	{
		exe->ac++;
		exe->av[exe->ac - 1] = ast->left->data;
		exe->av[exe->ac] = NULL;
		get_av_cmd_suffix(ast->right, exe);
	}
	else if (ast->type == AST_io_file)
	{
		exe->redirect_op = ast->data;
		exe->redirect_des = (ft_strequ(ast->data, ">") || \
			ft_strequ(ast->data, ">>")) ? ast->left->data : NULL;
		exe->redirect_src = (ft_strequ(ast->data, "<")) ? ast->left->data : NULL;
	}
}
