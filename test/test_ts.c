/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:22:01 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/02 16:25:08 by ihwang           ###   ########.fr       */
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
	t.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t);

	tgetent(NULL, getenv("TERM"));
	int i = 5;
	char	buf[10];

	memset(buf, 0, sizeof(buf));
	while (i-- > 0)
	{
		read(0, buf, sizeof(buf));
		ft_putstr_fd(buf, 1);
	}
	char *str = tgetstr("ts", NULL);

	str = NULL;
	ft_putstr_fd(tgoto(tgetstr("ts", NULL), 0, 2), 0);

	return (0);
}
