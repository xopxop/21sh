/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:04:36 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 01:00:47 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		newline(char **strlst, char **line, int fd)
{
	char	*temp;
	int		i;

	i = 0;
	while (strlst[fd][i] != '\n' && strlst[fd][i] != '\0')
		i++;
	if (strlst[fd][i] == '\n')
	{
		*line = ft_strsub(strlst[fd], 0, i);
		temp = ft_strdup(strlst[fd] + i + 1);
		free(strlst[fd]);
		strlst[fd] = temp;
	}
	else if (strlst[fd][i] == '\0')
	{
		*line = ft_strdup(strlst[fd]);
		ft_strdel(&strlst[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*strlst[FD_SIZE];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (strlst[fd] == NULL)
			strlst[fd] = ft_strnew(1);
		tmp = ft_strjoin(strlst[fd], buf);
		free(strlst[fd]);
		strlst[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (strlst[fd] == NULL || strlst[fd][0] == '\0'))
		return (0);
	return (newline(strlst, line, fd));
}
