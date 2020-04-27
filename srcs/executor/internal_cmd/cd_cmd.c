/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 02:24:33 by dthan             #+#    #+#             */
/*   Updated: 2020/03/30 02:24:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	cd_cmd(char **tokens)
{
	struct stat	s;
	char		*path;

	if (tokens[0] && tokens[1])
		error_monitor(CD_ENOPWD, NULL, NULL, NULL, 0 , 0);
	else
	{
		if (*tokens == NULL)
			path = ft_call_value_of("HOME");
		else if (tokens[0] && !tokens[1])
			path = *tokens;
		if (access(path, F_OK) == -1)
			return ((void)error_monitor(CD_ENOENT, path, NULL, NULL, 0, 0));
		lstat(path, &s);
		if (access(path, R_OK) == -1)
			return ((void)error_monitor(CD_EACCES, path, NULL, NULL, 0, 0));
		if (!S_ISDIR(s.st_mode))
			return ((void)error_monitor(CD_ENOTDIR, path, NULL, NULL, 0, 0));
		chdir(path);
		ft_strcpy(ft_call_value_of("OLDPWD"), ft_call_value_of("PWD"));
		getcwd(ft_call_value_of("PWD"), PATH_MAX);
	}
}
