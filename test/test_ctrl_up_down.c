/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ctrl_up_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 14:17:27 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/03 14:32:28 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = -1;
	while (str[++i])
		write(fd, &str[i], 1);
}

int main(void)
{
	struct termios t;

	tcgetattr(0, &t);
	t.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &t);

	tgetent(NULL, getenv("TERM"));
	int i = 5;
	char	buf[10];

	while (i-- > 0)
	{
		memset(buf, 0, sizeof(buf));
		read(0, buf, sizeof(buf));
		if (!strcmp(buf, "\x1b[1;5A"))
			printf("HI!");
	}
	return (0);
}
