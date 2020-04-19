/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:35:21 by dthan             #+#    #+#             */
/*   Updated: 2020/04/16 18:02:36 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void execute_list(t_astnode *ast, t_exe *exe, t_h **h)
{
	if (ast->type == AST_list)
	{
		execute_and_or(ast->left, exe, h);
		execute_list(ast->right, exe, h);
	}
	else
		execute_and_or(ast, exe, h);
}
