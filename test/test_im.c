/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_im.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:53:09 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/01 17:19:15 by ihwang           ###   ########.fr       */
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
	ft_putstr_fd(tgetstr("#4", NULL), 0);
	ft_putstr_fd(tgetstr("#4", NULL), 0);
	ft_putstr_fd(tgetstr("#4", NULL), 0);

	i = 5;
	memset(buf, 0, sizeof(buf));
	while (i-- > 0)
		read(0, buf, sizeof(buf));

	return (0);
}
