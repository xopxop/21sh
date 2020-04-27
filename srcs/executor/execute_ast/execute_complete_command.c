/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_complete_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:30:58 by dthan             #+#    #+#             */
/*   Updated: 2020/04/16 08:31:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void execute_complete_command(t_astnode *ast, t_exe *exe)
{
	if (ast->type == AST_complete_command)
		execute_list(ast->left, exe);
	else
		execute_list(ast, exe);
}