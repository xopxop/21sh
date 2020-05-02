/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:35:21 by dthan             #+#    #+#             */
/*   Updated: 2020/04/27 13:51:05 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	find_iofile(t_astnode *ast)
{
	if (ast->type == AST_io_file && \
	(ft_strequ(">", ast->data) || ft_strequ(">>", ast->data)))
	{
		int fd = open(ast->left->data, O_CREAT, \
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		close(fd);
	}
	else if (ast->type == AST_pipe_sequence)
	{
		find_iofile(ast->left);
		find_iofile(ast->right);
	}
	else if (ast->type == AST_simple_command)
		find_iofile(ast->right);
	else if (ast->type == AST_cmd_suffix)
	{
		find_iofile(ast->left);
		find_iofile(ast->right);
	}
}

void execute_list(t_astnode *ast, t_exe *exe)
{
	if (ast->type == AST_list)
	{
		find_iofile(ast->left);
		execute_and_or(ast->left, exe);
		execute_list(ast->right, exe);
	}
	else
	{
		find_iofile(ast);
		execute_and_or(ast, exe);
	}
}
