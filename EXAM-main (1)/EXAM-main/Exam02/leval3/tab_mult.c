/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 07:04:16 by malhendi          #+#    #+#             */
/*   Updated: 2025/12/11 07:04:16 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Simple atoi since we'll always get a strictly positive integer
int ft_atoi(char *s)
{
    int res = 0, i = 0;
    while (s[i] && s[i] >= 48 && s[i] <= 57)
    {
        res *= 10;
        res += s[i] - 48;
        i++;
    }
    return (res);
}

// Simple putnbr since we'll always get a strictly positive integer
void ft_putnbr(int nbr)
{
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    char c = nbr % 10 + '0';
    write(1, &c, 1);
}

void ft_putstr(char *s)
{
    int i = 0;
    while (s[i])
        write(1, &s[i++], 1);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    int i = 1, n = ft_atoi(av[1]);
    // Loop from 1 to 9
    // and print each line in the format [i x n = i*n]
    while (i < 10)
    {
        ft_putnbr(i);
        ft_putstr(" x ");
        ft_putnbr(n);
        ft_putstr(" = ");
        ft_putnbr(i * n);
        write(1, "\n", 1);
        i++;
    }
}