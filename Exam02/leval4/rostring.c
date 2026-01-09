#include <unistd.h>

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		int i = 0;
		int z = 0;
		int x = 0;
		int f = 0;

		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;

		int j = i;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			i++;
		x = i;
	
		while (av[1][i])
		{
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			if (!av[1][i])
				break;

			z = i;
			while (av[1][z] && av[1][z] != ' ' && av[1][z] != '\t')
				z++;

			if (f)
				write(1, " ", 1);
			write(1, &av[1][i], z - i);

			f = 1;
			i = z;
		}

		if (j < x)
		{
			if (f)
				write(1, " ", 1);
			while (j < x)
			{
				write(1, &av[1][j], 1);
				j++;
			}
		}
	}
	write(1, "\n", 1);
	return 0;
}
