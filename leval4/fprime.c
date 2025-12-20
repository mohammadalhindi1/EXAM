#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
	if(ac == 2)
	{
		int i = 2;
		int num = atoi(av[1]);
		
		if(num == 1)
		{
			printf("%d\n",num);
			return(0);
		}

		while(i <= num)
		{
			if(num % i == 0)
			{
				printf("%d",i);
				if(i != num)
					printf("*");
				num /= i;
			}
			else
				i++;
		}
	}
	printf("\n");
}
