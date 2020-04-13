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

#include "../includes/minishell.h"

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

static char	**ft_creat_argv(char **args, t_cmd_name *program_name, t_cmd_suffix *program_suffix)
{
	char **argv;
	int size;
	int i;
	t_cmd_suffix *p;

	i = 0;
	p = program_suffix;
	size = 0;
	size = (program_name) ? 1 : 0;
	if (p)
	{
		while (p->next)
			p = p->next;
		size += p->cmd_word->pos - program_suffix->cmd_word->pos + 1;
	}
	argv = (char**)malloc(sizeof(char*) * (size + 1));
	if (program_name)
		argv[i++] = program_name->cmd_word->data;
	while (program_suffix)
	{
		args[i++] = program_suffix->cmd_word->data;
		program_suffix = program_suffix->next;
	}
	argv[i] = NULL;
	return (argv);
}

static int	ft_external_cmd(t_cmd *cmd, t_pipe_sequence *pipe)
{
	char **p;
	char *bin_path;
	char **av;

	p = ft_strsplit(ft_call_value_of("PATH"), ':');
	while (*p)
	{
		bin_path = ft_strjoin(*p, "/");
		bin_path = ft_strjoin_and_free_string1(bin_path, pipe->simple_cmd->cmd_name->cmd_word->data);
		if (access(bin_path, F_OK) != -1)
		{
			av = ft_creat_argv(cmd->argv, pipe->simple_cmd->cmd_name, pipe->simple_cmd->cmd_suffix);
			ft_fork(bin_path, av);
			free(bin_path);
			ft_arraydel(av);
			return (EXIT_SUCCESS);
		}
		free(bin_path);
		p++;
	}
	ft_arraydel(p);
	ft_error_handle(SYNTAX_CMDNF, pipe->simple_cmd->cmd_name->cmd_word->data, NULL, NULL);
	return (EXIT_FAILURE);
}

static int	ft_internal_cmd(t_cmd *cmd, t_pipe_sequence *pipe)
{
	int			i;
	t_builtin	*get_built_in;
	char		**av;

	get_built_in = (t_builtin[8]) {
		{"echo", echo_cmd},
		{"cd", cd_cmd},
		{"setenv", setenv_cmd},
		{"unsetenv", unsetenv_cmd},
		{"env", env_cmd},
		{"exit", exit_cmd},
		{NULL, NULL}
	};
	i = -1;
	while (get_built_in[++i].command)
		if (ft_strcmp(pipe->simple_cmd->cmd_name->cmd_word->data, get_built_in[i].command) == 0)
		{
			av = ft_creat_argv(cmd->argv, NULL, pipe->simple_cmd->cmd_suffix);
			get_built_in[i].func(av);
			ft_arraydel(av);
			return (EXIT_SUCCESS);
		}
	return (EXIT_FAILURE);
}

void		executor(t_cmd *cmd, t_pipe_sequence *pipe)
{
	while (cmd)
	{
		ft_replace_args_if_env_var(cmd->argv);
		if (ft_internal_cmd(cmd, pipe) == EXIT_FAILURE && \
			ft_external_cmd(cmd, pipe) == EXIT_FAILURE)
			return ;
		cmd = cmd->next;
	}
}
