#include <stdlib.h>

int	ft_intlen(long n)
{
	int i = 0;

	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	long	n;
	int		len;
	char	*s;
	int		i;

	n = nbr;
	len = ft_intlen(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	i = len - 1;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		s[i--] = (n % 10) + '0';
		n /= 10;
	}
	s[i] = n + '0';
	if (nbr < 0)
		s[0] = '-';
	return (s);
}
