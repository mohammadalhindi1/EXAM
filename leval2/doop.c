/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi@student.42amman.com <malhendi>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 03:10:03 by malhendi@st       #+#    #+#             */
/*   Updated: 2025/11/29 03:10:04 by malhendi@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
	if(ac == 4)
	{
		int i = atoi(av[1]);
		int j = atoi(av[3]);
		
		if(av[2][0] == '+')
			printf("%i", i + j);
		else if(av[2][0] == '-')
			printf("%i", i - j);
		else if(av[2][0] == '*')
			printf("%i", i * j);
		else if(av[2][0] == '/')
			printf("%i", i / j);
		else if(av[2][0] == '%')
			printf("%i", i % j);
	}
	printf("\n");
}
