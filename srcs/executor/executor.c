/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 08:06:41 by dthan             #+#    #+#             */
/*   Updated: 2020/04/08 08:06:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_fork(char *path, char **arguments)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		execve(path, arguments, env); // execve(argment[0], arguments, env);
	else if (pid < 0)
		ft_printf("can not fork\n");
	wait(&pid);
}

static int	ft_external_cmd(t_exe cmd)
{
	char **p;
	char *bin_path;

	p = ft_strsplit(ft_call_value_of("PATH"), ':');
	while (*p)
	{
		bin_path = ft_strjoin(*p, "/");
		bin_path = ft_strjoin_and_free_string1(bin_path, cmd.av[0]);
		if (access(bin_path, F_OK) != -1)
		{
			ft_fork(bin_path, cmd.av);
			free(bin_path);
			return (EXIT_SUCCESS);
		}
		free(bin_path);
		p++;
	}
	ft_arraydel(p);
	error_monitor(SYNTAX_CMDNF, cmd.av[0], NULL, NULL, 0, 0);
	return (EXIT_FAILURE);
}

static int	ft_internal_cmd(t_exe cmd)
{
	int			i;
	t_builtin	*get_built_in;

	get_built_in = (t_builtin[7]) {
		// {"echo", echo_cmd},
		{"cd", cd_cmd},
		{"setenv", setenv_cmd},
		{"unsetenv", unsetenv_cmd},
		{"env", env_cmd},
		{"exit", exit_cmd},
		{NULL, NULL}
	};
	i = -1;
	while (get_built_in[++i].command)
		if (ft_strcmp(cmd.av[0], get_built_in[i].command) == 0)
		{
			get_built_in[i].func(&cmd.av[1]);
			return (EXIT_SUCCESS);
		}
	return (EXIT_FAILURE);
}

void run2 (t_exe exec)
{
	if (ft_external_cmd(exec) == EXIT_FAILURE)
		error_monitor(SYNTAX_CMDNF, exec.av[0], NULL, NULL, 0 , 0);
}

void redirect_great(char *des)
{
	int fd;
	
	fd = open(des, O_WRONLY | O_TRUNC);
	// need to handle error
	dup2(fd, STDOUT_FILENO);
}

void redirect_dgreat(char *des)
{
	int fd;
	
	fd = open(des, O_WRONLY | O_APPEND);
	// need to handle error
	dup2(fd, STDOUT_FILENO);
}

void redirect_less(char *src)
{
	int fd;
	
	fd = open(src, O_RDONLY);
	if (fd == -1)
		error_monitor(SHELL_ENOENT, src, NULL, NULL, 0, EXIT_FAILURE);
	dup2(fd, STDIN_FILENO);
}

void redirect_dless(t_exe exe)
{
	int fd[2];

	(void)exe;
	pipe(fd);
	write(fd[WRITE_END], exe.redirect_des, ft_strlen(exe.redirect_des));
	close(fd[WRITE_END]);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
}

void handle_redirect(t_exe exe)
{
	if (ft_strequ(exe.redirect_op, ">"))
		return (redirect_great(exe.redirect_des));
	if (ft_strequ(exe.redirect_op, ">>"))
		return (redirect_dgreat(exe.redirect_des));
	if (ft_strequ(exe.redirect_op, "<"))
		return (redirect_less(exe.redirect_src));
	if (ft_strequ(exe.redirect_op, "<<"))
		return (redirect_dless(exe));
}

// void run (t_exe exec)
// {
// 	if (ft_internal_cmd(exec) == EXIT_SUCCESS)
// 		return ;
// 	if (fork() == 0)
// 	{
// 		if (exec.redirect_op != NULL)
// 			handle_redirect(exec);
// 		if (ft_strequ(exec.av[0], "echo"))
// 		{
// 			echo_cmd(&exec.av[1]);
// 			exit(EXIT_SUCCESS);
// 		}
// 		run2(exec);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 		wait(NULL);
// }

void run (t_exe exec)
{
	if (ft_internal_cmd(exec) == EXIT_SUCCESS)
		return ;
	if (fork() == 0)
	{
		if (exec.redirect_op != NULL)
			handle_redirect(exec);
		(ft_strequ(exec.av[0], "echo")) ? echo_cmd(&exec.av[1]) : run2(exec);
	}
	else
		wait(NULL);
}


void executor(t_astnode *ast)
{
	t_exe exec;

	printBinaryTree(ast);
	ft_bzero(&exec, sizeof(t_exe));
	exec.av = (char**)malloc(sysconf(_SC_ARG_MAX));
	execute_complete_command(ast, &exec);
}
