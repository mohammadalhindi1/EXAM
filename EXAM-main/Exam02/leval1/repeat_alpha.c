/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi@student.42amman.com <malhendi>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:05:01 by malhendi@st       #+#    #+#             */
/*   Updated: 2025/11/27 16:05:06 by malhendi@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char *av[])
{
	if(ac == 2)
	{
		int i = 0;
		int j = 0;
		while(av[1][i])
		{
			if(av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				j = av[1][i] - 96;
				while(j > 0)
				{
					write(1, &av[1][i], 1);
					j--;
				}
			}
			else if(av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				j = av[1][i] - 64;
				while(j > 0)
				{
					write(1, &av[1][i], 1);
					j--;
				}
			}
			else
				write(1, &av[1][i],1);
			i++;
		}
	}
	write(1, "\n", 1);
}
