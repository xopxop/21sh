/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 03:08:48 by dthan             #+#    #+#             */
/*   Updated: 2020/03/30 03:08:49 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_find_env(char *name, char **env)
{
	int i;

	while (*env)
	{
		i = ft_strlen(name);
		if (!ft_strncmp(name, *env, i))
			if (*(*env + i) == '=')
				return (&*(*env + i));
		env++;
	}
	return (NULL);
}

void	ft_fork(char *path, char **arguments, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		execve(path, arguments, env);
	else if (pid < 0)
		ft_printf("can not fork\n");
	wait(&pid);
}

void	ft_free_old_env(char **old_env)
{
	char *ptr;

	while (*old_env)
	{
		ptr = *old_env;
		old_env++;
		free(ptr);
	}
	ptr = *old_env;
	free(ptr);
}
