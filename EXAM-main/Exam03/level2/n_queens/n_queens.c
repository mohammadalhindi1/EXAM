/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:22:14 by malhendi          #+#    #+#             */
/*   Updated: 2026/01/26 19:22:14 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_solution(int *board, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		if (i != n - 1)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int *board, int col, int row)
{
	int i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		if (board[i] - i == row - col)
			return (0);
		if (board[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *board, int col, int n)
{
	int row;

	if (col == n)
	{
		print_solution(board, n);
		return;
	}
	row = 0;
	while (row < n)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			solve(board, col + 1, n);
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	int n;
	int board[20];

	if (argc != 2)
		return (0);
	n = atoi(argv[1]);
	if (n <= 0 || n > 20)
		return (0);
	solve(board, 0, n);
	return (0);

}
