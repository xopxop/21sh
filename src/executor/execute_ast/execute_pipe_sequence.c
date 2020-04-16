/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_sequence.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:37:39 by dthan             #+#    #+#             */
/*   Updated: 2020/04/16 08:37:43 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void execute_pipe_sequence(t_astnode *ast, t_exe *exec)
{
	if (ast->type == AST_pipe_sequence)
	{
		execute_command(ast, exec);
		execute_pipe_sequence(ast, exec);
	}
	else
		execute_command(ast, exec);
}
