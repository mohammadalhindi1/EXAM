#include <unistd.h>

int ft_atoi(char *s)
{
	int i = 0;
	int t = 0;
	while(s[i])
	{
		t = t * 10 + (s[i] - 48);
		i++;
	}
	return (t);
}
int ft_is_prime(int n)
{
	if(n < 2)
		return (0);
	int i = 2;
	while (i <= n/2)
	{
		if(n % i == 0)
			return(0);
		i++;
	}
	return(1);
}

void ft_print_num(int i)
{
	if(i > 9)
		ft_print_num(i / 10);
	write(1,&"0123456789"[i % 10],1);
}

int main(int ac, char *av[])
{
	if(ac == 2)
	{
		int n = 0;
		int sum = 0;

		n = ft_atoi(av[1]);
		while(n > 1)
		{
			if(ft_is_prime(n))
			{
				sum += n;
			}
			n--;
		}
		ft_print_num(sum);
	}
	write(1, "\n", 1);
}

