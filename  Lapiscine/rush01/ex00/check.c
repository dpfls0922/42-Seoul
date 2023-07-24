/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:19:42 by sebang            #+#    #+#             */
/*   Updated: 2023/01/22 13:25:38 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int *board, int *clues, int col_no)
{
	int	seen;
	int	idx;
	int	curr;

	idx = col_no;
	seen = 1;
	curr = board[idx];
	while (idx <= 12 + col_no)
	{
		if (board[idx] > curr)
		{
			seen++;
			curr = board[idx];
		}
		idx += 4;
	}
	return (seen == clues[col_no]);
}

int	check_col_down(int *board, int *clues, int col_no)
{
	int	seen;
	int	idx;
	int	curr;

	idx = 12 + col_no;
	seen = 1;
	curr = board[idx];
	while (idx >= col_no)
	{
		if (board[idx] > curr)
		{
			seen++;
			curr = board[idx];
		}
		idx -= 4;
	}
	return (seen == clues[4 + col_no]);
}

int	check_row_left(int *board, int *clues, int row_no)
{
	int	seen;
	int	idx;
	int	curr;

	idx = 4 * row_no;
	seen = 1;
	curr = board[idx];
	while (idx <= 3 + 4 * row_no)
	{
		if (board[idx] > curr)
		{
			seen++;
			curr = board[idx];
		}
		idx += 1;
	}
	return (seen == clues[8 + row_no]);
}

int	check_row_right(int *board, int *clues, int row_no)
{
	int	seen;
	int	idx;
	int	curr;

	idx = 3 + 4 * row_no;
	seen = 1;
	curr = board[idx];
	while (idx >= 4 * row_no)
	{
		if (board[idx] > curr)
		{
			seen++;
			curr = board[idx];
		}
		idx -= 1;
	}
	return (seen == clues[12 + row_no]);
}

int	check_all_clue(int *board, int *clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_row_left(board, clues, i))
			return (0);
		if (!check_row_right(board, clues, i))
			return (0);
		if (!check_col_up(board, clues, i))
			return (0);
		if (!check_col_down(board, clues, i))
			return (0);
		i++;
	}
	return (1);
}
