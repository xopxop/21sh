/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 21:27:20 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/11 21:27:59 by ihwang           ###   ########.fr       */
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
	write(fd, "tiger", 5);
	close(fd);

	return (0);
}
