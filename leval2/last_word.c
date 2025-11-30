#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	int end;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
			i++;
		i--;
		while (i >= 0 && (av[1][i] == ' ' || (av[1][i] >= 9 && av[1][i] <= 13)))
			i--;
		end = i;
		while (i >= 0 && av[1][i] != ' ' && !(av[1][i] >= 9 && av[1][i] <= 13))
			i--;
		i++;
		while (i <= end)
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
