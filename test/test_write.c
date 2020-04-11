/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 01:27:45 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/11 21:28:00 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	char buf[30];
	int fd;
	
	bzero(buf, sizeof(buf));
	fd = open("./.history.txt", O_RDWR | O_CREAT, 0644);
	write(fd, "HI?\n", 4);
	close(fd);

	return (0);
}
