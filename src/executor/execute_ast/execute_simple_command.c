/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:39:32 by dthan             #+#    #+#             */
/*   Updated: 2020/04/16 08:39:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void execute_simple_command(t_astnode *ast, t_exe *exe)
{
	if (ast->type == AST_simple_command)
	{
		exe->ac = count_av(ast);
		exe->av = (char**)malloc(sizeof(char*) * (exe->ac + 1));
		create_av(ast, exe->av);
	}
	else if (ast->type == AST_WORD)
	{
		exe->ac = 1;
		exe->av = (char**)malloc(sizeof(char*) * 2);
		exe->av[0] = ast->data;
		exe->av[1] = NULL;
	}
	run(exe);
}
