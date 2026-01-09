#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
	if(ac == 3)
	{
		int i = atoi(av[1]);
		int j = atoi(av[2]);

		while(i != j)
		{
			if(i > j)
				i -= j;
			else if(j > i)
				j -= i;
		}
		printf("%d",i);
	}
	printf("\n");
}
