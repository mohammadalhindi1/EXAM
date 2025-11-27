/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi@student.42amman.com <malhendi>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:15:14 by malhendi@st       #+#    #+#             */
/*   Updated: 2025/11/27 15:15:14 by malhendi@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putnum(int n)
{
    char c;

    if (n > 9)
        putnum(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}

int main(void)
{
	int i = 1;
	
	while(i < 101)
	{
		if(i % 3 == 0 && i % 5 == 0)
		{
			write(1, "fizzbuzz\n", 9);
		}
		else if(i % 5 == 0)
		{
			write(1, "buzz\n", 5);
		}
		else if(i % 3 == 0)
		{
			write(1, "fizz\n", 5);
		}
		else
		{
			putnum(i);
			write(1, "\n", 1);
		}
		i++;
	}	
}