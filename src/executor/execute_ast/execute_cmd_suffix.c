/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:14:52 by dthan             #+#    #+#             */
/*   Updated: 2020/08/05 05:49:02 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_redirect			*get_last_redi_node(t_exe *exe)
{
	t_redirect		*p;

	if (exe->redi == NULL)
	{
		p = (t_redirect*)malloc(sizeof(t_redirect));
		ft_bzero(p, sizeof(t_redirect));
		exe->redi = p;
	}
	else
	{
		p = exe->redi;
		while (p->next)
			p = p->next;
	}
	return (p);
}

t_redirect			*new_redi_node(t_redirect *last_node)
{
	t_redirect		*new_node;

	new_node = (t_redirect*)malloc(sizeof(t_redirect));
	ft_bzero(new_node, sizeof(t_redirect));
	last_node->next = new_node;
	return (new_node);
}

void				get_redi_data(t_astnode *ast, t_exe *exe)
{
	t_redirect		*last_node;

	last_node = get_last_redi_node(exe);
	if (last_node->redirect_op && last_node->redirect_src && \
		last_node->redirect_des)
		last_node = new_redi_node(last_node);
	if (ast->type == AST_io_redirect)
		last_node->redirect_src = ast->data;
	else if (ast->type == AST_io_file)
		last_node->redirect_op = ast->data;
	else
		last_node->redirect_des = ast->data;
}

void				get_av_cmd_suffix(t_astnode *ast, t_exe *exe, int opt)
{
	if (ast->type == AST_WORD && opt == 0)
	{
		exe->ac++;
		exe->av[exe->ac - 1] = ast->data;
		exe->av[exe->ac] = NULL;
	}
	else if (ast->type == AST_cmd_suffix)
	{
		get_av_cmd_suffix(ast->left, exe, 0);
		get_av_cmd_suffix(ast->right, exe, 0);
	}
	else if (ast->type == AST_io_redirect)
	{
		get_redi_data(ast, exe);
		get_av_cmd_suffix(ast->right, exe, 0);
	}
	else if (ast->type == AST_io_file)
	{
		get_redi_data(ast, exe);
		get_av_cmd_suffix(ast->left, exe, 1);
	}
	else if (opt)
		get_redi_data(ast, exe);
}
