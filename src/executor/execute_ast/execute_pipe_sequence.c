/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_sequence.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:37:39 by dthan             #+#    #+#             */
/*   Updated: 2020/04/20 22:07:00 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_pipe_sequence(t_astnode *ast, t_exe *exec, t_h **h)
{
	int pipefd[2];
	int status;
	pid_t pid[2];

	if (ast->type == AST_pipe_sequence)
	{
		pipe(pipefd);
		pid[0] = fork();
		if (pid[0] == 0)
		{
			close(pipefd[READ_END]);
			dup2(pipefd[WRITE_END], STDOUT_FILENO);
			execute_command(ast->left, exec, h);
			exit(EXIT_SUCCESS);
		}
		pid[1] = fork();
		if (pid[1] == 0)
		{
			close(pipefd[WRITE_END]);
			dup2(pipefd[READ_END], STDIN_FILENO);
			execute_pipe_sequence(ast->right, exec, h);
			exit(EXIT_SUCCESS);
		}
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(pid[0], &status, 0);
		waitpid(pid[1], &status, 0);
	}
	else
		execute_command(ast, exec, h);
}
