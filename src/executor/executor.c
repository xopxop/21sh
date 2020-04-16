/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 08:06:41 by dthan             #+#    #+#             */
/*   Updated: 2020/04/16 18:19:40 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int		is_builtin(char *comm)
{
	if (!ft_strcmp(comm, "exit") || !ft_strcmp(comm, "echo")
			|| !ft_strcmp(comm, "cd") || !ft_strcmp(comm, "env")
			|| !ft_strcmp(comm, "setenv") || !ft_strcmp(comm, "unsetenv")
			|| !ft_strcmp(comm, "pwd"))
		return (1);
	return (0);
}

static void		run_builtin(t_exe *coms)
{
	if (!ft_strcmp(coms->av[0], "exit"))
	 	ft_exit(coms, NORM); // Not done. need more 'free'
	if (!ft_strcmp(coms->av[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(coms->av[0], "cd"))
	 	ft_cd(coms);
	else if (!ft_strcmp(coms->av[0], "env"))
		ft_env();
	else if (!ft_strcmp(coms->av[0], "echo"))
		ft_echo(coms);
	else if (!ft_strcmp(coms->av[0], "setenv"))
	 	ft_setenv(coms);
	else if (!ft_strcmp(coms->av[0], "unsetenv"))
	 	ft_unsetenv(coms);
}

void run (t_exe *c)
{
	// char *path;

	// path = NULL;
	if (is_builtin(c->av[0]))
		return (run_builtin(c));
	// else if ((path = is_in_path(c)))
	// 	return (make_child_env(c, path));
	// if (there_is_p(c))
	// 	make_child_not_env(c);
	// else if (c->av[0][0] != '.' && c->av[0][0] != '/')
	// 	print_no_cmd(c->av[0]);
}

/*<<<<<<< HEAD
=======
int		count_av(t_astnode *ast)
{
	int ct;

	ct = 0;
	while (ast)
	{
		ct++;
		ast = ast->right;
	}
	return (ct);
}

void create_av(t_astnode *ast, char **av)
{
	int i;

	i = 0;
	av[i++] = ft_strdup(ast->left->data);
	if (ast->right && (ast->right->type != AST_cmd_suffix))
		av[i++] = ft_strdup(ast->right->data);
	else if (ast->right && (ast->right->type == AST_cmd_suffix))
	{
		ast = ast->right;
		while (ast && ast->type == AST_cmd_suffix)
		{
			av[i++] = ft_strdup(ast->left->data);
			ast = ast->right;
		}
		av[i++] = ft_strdup(ast->data);
	}
	av[i] = NULL;
}

void init(t_astnode *ast, t_exe *exec)
{
	if (ast->type == AST_simple_command)
	{
		exec->ac = count_av(ast);
		exec->av = (char**)malloc(sizeof(char*) * (exec->ac + 1));
		create_av(ast, exec->av);
	}
	else if (ast->type == AST_WORD)
	{
		exec->ac = 1;
		exec->av = (char**)malloc(sizeof(char*) * 2);
		exec->av[0] = ast->data;
		exec->av[1] = NULL;
	}
}

>>>>>>> ihwang_sync_builtin */
void executor(t_astnode *ast)
{
	t_exe exec;

	printBinaryTree(ast);
	ft_bzero(&exec, sizeof(t_exe));
	execute_complete_command(ast, &exec);
}
