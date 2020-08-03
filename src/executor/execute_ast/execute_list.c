/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:35:21 by dthan             #+#    #+#             */
/*   Updated: 2020/08/02 01:59:57 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_iofile(t_astnode *ast, char *redirect_op)
{
	int fd;

	if (ast->type == AST_io_file && (ft_strequ(">", ast->data) || \
		ft_strequ(">&", ast->data) || ft_strequ(">>", ast->data)))
		open_iofile(ast->left, ast->data);
	else if (ast->type == AST_WORD)
	{
		if (!(ft_strequ(redirect_op, ">&") && (ft_strequ(ast->data, "-") || \
			is_made_of_digits(ast->data))))
		{
			fd = open(ast->data, O_CREAT, 0644);
			close(fd);
		}
	}
}

void	find_iofile(t_astnode *ast)
{
	if (ast->type == AST_io_redirect)
		open_iofile(ast->right, NULL);
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

void	execute_list(t_astnode *ast, t_exe *exe)
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
