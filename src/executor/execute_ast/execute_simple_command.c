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

// void execute_simple_command(t_astnode *ast, t_exe *exe)
// {
// 	if (ast->type == AST_simple_command)
// 	{
// 		exe->ac = count_av(ast);
// 		exe->av = (char**)malloc(sizeof(char*) * (exe->ac + 1));
// 		create_av(ast, exe->av);
// 	}
// 	else if (ast->type == AST_WORD)
// 	{
// 		exe->ac = 1;
// 		exe->av = (char**)malloc(sizeof(char*) * 2);
// 		exe->av[0] = ft_strdup(ast->data);
// 		exe->av[1] = NULL;
// 	}
// 	else if (ast->type == AST_io_file)
// 	{
// 		exe->ac = 1;
// 		exe->av = (char**)malloc(sizeof(char*) * 3);
// 		exe->av[0] = ft_strdup(ast->data);
// 		exe->av[1] = ft_strdup(ast->left->data)
// 		exe->av[1] = NULL;
// 	}
// 	run(*exe);
// }

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
}
