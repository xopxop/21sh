/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 00:47:21 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/02 00:47:41 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	struct termios t;

	tcgetattr(0, &t);
	t.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t);

	int	i = 10;
	char buf[10];
	memset(buf, 0, sizeof(buf));
	while (i-- > 0)
		read(0, buf, sizeof(buf));



	return (0);
}
