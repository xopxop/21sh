/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:35:21 by dthan             #+#    #+#             */
/*   Updated: 2020/04/16 08:35:22 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	find_iofile(t_astnode *ast)
{
	t_astnode *ptr;

	ptr = ast;
	while (ptr)
	{
		if (ptr->type == AST_io_file && \
			(ft_strequ(">", ptr->data) || ft_strequ(">>", ptr->data)))
		{
			int fd = open(ptr->left->data, O_CREAT, \
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			close(fd);
		}
		ptr = ptr->right;
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
	// need to reser redirect
}
