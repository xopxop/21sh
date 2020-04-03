/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 14:50:52 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/03 14:51:24 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

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
	t.c_lflag &= ~ICANON;
	tcsetattr(0, TCSANOW, &t);

	tgetent(NULL, getenv("TERM"));
	int i = 10;
	char	buf[10];

	while (i-- > 0)
	{
		memset(buf, 0, sizeof(buf));
		read(0, buf, sizeof(buf));
	}
	ft_putstr_fd(tgetstr("up", NULL), 0);
	return (0);
}
