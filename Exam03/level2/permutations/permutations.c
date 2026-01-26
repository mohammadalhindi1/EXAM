/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:22:14 by malhendi          #+#    #+#             */
/*   Updated: 2026/01/26 19:22:14 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int str_len(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void swap (char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(char *s)
{
	int i =0;
	int j;

	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
			j++;
		}
		i++;
	}
}

void sort_from(char *s, int start)
{
	int i = start;
	int j;

	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
			j++;
		}
		i++;
	}
}


void permute(char *s, int start)
{
	int i;
	int len = str_len(s);

	if (start == len)
	{
		write(1, s, len);
		write (1, "\n", 1);
		return ;
	}

	i = start;
	while (i < len)
	{
		sort_from(s, start);
		swap(&s[start], &s[i]);
		permute(s, start + 1);
		swap(&s[start], &s[i]);
		i++;
	}
}


int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	sort(argv[1]);
	permute(argv[1], 0);
	return (0);

}
