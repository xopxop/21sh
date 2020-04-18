#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int main(void)
{
	struct termios t;
	struct termios old;
	char buf[5];
	int	i;

	tcgetattr(1, &t);
	old = t;
	t.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(1, TCSANOW, &t);
	i = 5;
	tgetent(NULL, getenv("TERM"));
	while (i--)
	{
		memset(buf, 0, sizeof(buf));
		read(0, buf, sizeof(buf));
		ft_putchar(buf[0]);
	}
	tputs(tgetstr("kl", NULL), 1, ft_putchar); 
	tputs(tgetstr("kl", NULL), 1, ft_putchar); 
	tputs(tgetstr("cd", NULL), 1, ft_putchar); 
	tcsetattr(1, TCSANOW, &old);
	return  (0);
}
