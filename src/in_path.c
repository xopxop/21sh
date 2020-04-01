/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:52:07 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/28 19:03:20 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh.h"

static int	is_in_path_sub2(char *str, t_cmd *c)
{
	DIR		*dirp;
	t_dir	*dir;

	if ((dirp = opendir(str)))
	{
		while ((dir = readdir(dirp)))
		{
			if (!ft_strcmp(dir->d_name, c->av[0]))
			{
				closedir(dirp);
				return (1);
			}
		}
		closedir(dirp);
	}
	return (0);
}

static char	**check_path(t_cmd *c)
{
	char	*path;

	if (c->av[0][0] == '.' || c->av[0][0] == '/')
		return (NULL);
	if ((path = get_env("PATH=", VAL)))
		return (ft_strsplit(path, ':'));
	else
		return (NULL);
}

char		*is_in_path(t_cmd *c)
{
	int		i;
	int		nb;
	char	**split;
	char	*path;

	if (!(split = check_path(c)))
		return (NULL);
	nb = -1;
	while (split[++nb])
		NULL;
	i = -1;
	while (++i < nb)
	{
		if (is_in_path_sub2(split[i], c))
		{
			path = ft_strnew(PATH_MAX);
			ft_strcpy(path, split[i]);
			ft_strlst_del(&split, nb + 1);
			return (path);
		}
	}
	ft_strlst_del(&split, nb + 1);
	return (NULL);
}
