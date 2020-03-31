/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 01:39:52 by dthan             #+#    #+#             */
/*   Updated: 2019/11/08 04:32:10 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# define FD_MAX 256
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

int	get_next_line(int fd, char **line);

#endif
