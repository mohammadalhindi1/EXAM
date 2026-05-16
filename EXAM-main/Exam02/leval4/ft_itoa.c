/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 07:03:41 by malhendi          #+#    #+#             */
/*   Updated: 2025/12/11 07:03:41 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}

	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';

	if (num < 0)
		num = -num;

	if (num == 0)
		str[0] = '0';

	while (num)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}

	if (n < 0)
		str[0] = '-';
	return (str);
}
*/