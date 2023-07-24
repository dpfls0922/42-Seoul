/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:54:31 by yerilee           #+#    #+#             */
/*   Updated: 2023/07/24 23:21:38 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int x, int y)
{
	if (x >= y)
		return (x - y);
	else
		return (y - x);
}

int	queen_valid(int row, char *board)
{
	int		i;

	if (row == 0)
		return (1);
	i = row - 1;
	while (i >= 0)
	{
		if (board[i] == board[row])
			return (0);
		else if (ft_abs(i, row) == ft_abs(board[i], board[row]))
			return (0);
		i--;
	}
	return (1);
}

void	make_board(int row, char *board, int *cnt)
{
	char	i;

	i = '0';
	if (row == 10)
	{
		write(1, board, 10);
		write(1, "\n", 1);
		(*cnt)++;
	}
	else
	{
		i = '0';
		while (i <= '9')
		{
			board[row] = i;
			if (queen_valid(row, board))
				make_board(row + 1, board, cnt);
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10];
	int		cnt;

	cnt = 0;
	make_board(0, board, &cnt);
	return (cnt);
}
