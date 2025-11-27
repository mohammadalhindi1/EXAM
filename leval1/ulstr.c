#include <unistd.h>

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		int i = 0;
		while(av[1][i])
		{
			if(av[1][i] > 64 && av[1][i] < 91)
				av[1][i] += 32;
			else if(av[1][i] > 96 && av[1][i] < 123)
				av[1][i] -= 32;	
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
