/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:20:36 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/02 20:45:02 by ihwang           ###   ########.fr       */
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
	ft_putstr_fd(tgetstr("#4", NULL), 0);
	ft_putstr_fd(tgetstr("#4", NULL), 0);
	//ft_putstr_fd(tgetstr("dc", NULL), 0);
	ft_putstr_fd(tgoto(tgetstr("DC", NULL), 0, 1), 0);

	return (0);
}
