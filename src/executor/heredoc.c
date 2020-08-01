/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <ihwang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:17:58 by dthan             #+#    #+#             */
/*   Updated: 2020/07/30 19:32:32 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** Note form dthanfor future improvement:
** Question:
** 1. what happens when heredoc prompt fails, should it returns failure,
** 2. When user hit ctlr D, or ctrl C to get out of the prompt in case he/she
** doesnt know how heredoc work, it needs to free all the memory allocation?
*/

/*static char	*prompt_heredoc(char *end_word)
{
	char *line;

	ft_putstr("heredoc> ");
	if (get_next_line(STDOUT_FILENO, &line) <= 0)
		return (NULL); //it should be return an error here
	if (ft_strequ(line, end_word))
	{
		ft_strdel(&line);
		return (NULL);
	}
	else
	{
		line = ft_strjoin_and_free_string1(line, "\n");
		line = ft_strjoin_and_free_string2(line, prompt_heredoc(end_word));
	}
	return (line);
}
*/

static char	*prompt_heredoc(char *end_word)
{
	t_l l;

	ft_memset(&l, 0, sizeof(t_l));
	l.type = LINE_TYPE_HEREDOC;
	l.pmpt = 9;
	ft_putstr("heredoc> ");
	ft_get_line(&l, &g_h);
	if (ft_strequ(l.line, end_word) || ft_strequ(l.line, "\x04"))
	{
		ft_strdel(&l.line);
		return (NULL);
	}
	else
	{
		l.line = ft_strjoin_and_free_string1(l.line, "\n");
		l.line = ft_strjoin_and_free_string2(l.line, prompt_heredoc(end_word));
	}
	return (l.line);
}

static void	push_node_into_heredoc(t_heredoc *node, t_heredoc **head)
{
	t_heredoc *p;

	if (*head == NULL)
		*head = node;
	else
	{
		p = *head;
		while (p->next)
			p = p->next;
		p->next = node;
	}
}

static void	apply_heredoc(t_astnode *heredoc, t_exe *exe)
{
	t_heredoc *node;

	node = (t_heredoc*)malloc(sizeof(t_heredoc)); 
	node->heredoc = prompt_heredoc(heredoc->data);
	node->next = NULL;
	push_node_into_heredoc(node, &exe->heredoc);
}

void	find_heredoc(t_astnode *ast, t_exe *exe)
{
	if (ast->type == AST_io_file && ft_strequ(ast->data, "<<"))
		apply_heredoc(ast->left, exe);
	else if (ast->type == AST_io_redirect)
		find_heredoc(ast->right, exe);
	else if (ast->type == AST_complete_command)
		find_heredoc(ast->left, exe);
	else if (ast->type == AST_list)
	{
		find_heredoc(ast->left, exe);
		find_heredoc(ast->right, exe);
	}
	else if (ast->type == AST_pipe_sequence)
	{
		find_heredoc(ast->left, exe);
		find_heredoc(ast->right, exe);
	}
	else if (ast->type == AST_simple_command)
		find_heredoc(ast->right, exe);
	else if (ast->type == AST_cmd_suffix)
	{
		find_heredoc(ast->left, exe);
		find_heredoc(ast->right, exe);
	}
}
