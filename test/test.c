#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
	while (i--)
	{
		memset(buf, 0, sizeof(buf));
		read(0, buf, sizeof(buf));
		ft_putchar(buf[0]);
	}
	tcsetattr(1, TCSANOW, &old);





	return  (0);
}
