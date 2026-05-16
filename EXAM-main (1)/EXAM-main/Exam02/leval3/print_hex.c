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

char print_h(int n)
{
	if(n >= 16)
		print_h(n / 16);
	write(1,&"0123456789abcdef"[n % 16],1);
}

int main(int ac, char *av[])
{
	if(ac == 2)
		print_h(ft_atoi(av[1]));
	write(1, "\n",1);
}
