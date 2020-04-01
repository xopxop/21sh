/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:53:09 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/01 18:10:02 by ihwang           ###   ########.fr       */
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
	ft_putstr_fd(tgetstr("im", NULL), 0);
	int i = 5;
	char	buf[10];

	memset(buf, 0, sizeof(buf));
	while (i-- > 0)
		read(0, buf, sizeof(buf));

	char *str = tgetstr("kb", NULL);

	str = NULL;
	ft_putstr_fd(tgetstr("kb", NULL), 0);
	ft_putstr_fd(tgetstr("kb", NULL), 0);
	ft_putstr_fd(tgetstr("kb", NULL), 0);

	i = 5;
	memset(buf, 0, sizeof(buf));
	while (i-- > 0)
		read(0, buf, sizeof(buf));

	ft_putstr_fd(tgetstr("ei", NULL), 0);
	return (0);
}
