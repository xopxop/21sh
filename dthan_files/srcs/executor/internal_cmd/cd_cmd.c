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
		ft_error_handle(CD_ENOPWD, NULL, NULL, NULL);
	else
	{
		if (*tokens == NULL)
			path = ft_call_value_of("HOME");
		else if (tokens[0] && !tokens[1])
			path = *tokens;
		if (access(path, F_OK) == -1)
			return (ft_error_handle(CD_ENOENT, path, NULL, NULL));
		lstat(path, &s);
		if (access(path, R_OK) == -1)
			return (ft_error_handle(CD_EACCES, path, NULL, NULL));
		if (!S_ISDIR(s.st_mode))
			return (ft_error_handle(CD_ENOTDIR, path, NULL, NULL));
		chdir(path);
		ft_strcpy(ft_call_value_of("OLDPWD"), ft_call_value_of("PWD"));
		getcwd(ft_call_value_of("PWD"), PATH_MAX);
	}
}
