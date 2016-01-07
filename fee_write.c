/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/05 20:56:13 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

void	fee_write_sharp_3j(t_tetrimino t, char **grid, int x, int y)
{
	grid[y][x] = t.ord;
	grid[y + 1][x] = t.ord;
	grid[y + 2][x] = t.ord;
	if (t.id == 2)
		grid[y + 2][x - 1] = t.ord;
	else if (t.id == 6)
		grid[y + 2][x + 1] = t.ord;
	else if (t.id == 9)
		grid[y + 1][x + 1] = t.ord;
	else if (t.id == 12)
		grid[y + 1][x - 1] = t.ord;
	else if (t.id == 13)
		grid[y + 3][x] = t.ord;
}

void	fee_write_sharp_3i(t_tetrimino t, char **grid, int x, int y)
{
	grid[y][x] = t.ord;
	grid[y][x + 1] = t.ord;
	grid[y][x + 2] = t.ord;
	if (t.id == 4)
		grid[y + 1][x + 2] = t.ord;
	else if (t.id == 8)
		grid[y + 1][x] = t.ord;
	else if (t.id == 10)
		grid[y + 1][x + 1] = t.ord;
	else if (t.id == 14)
		grid[y][x + 3] = t.ord;
}

void	fee_write_sharp_2j(t_tetrimino t, char **grid, int x, int y)
{
	grid[y][x] = t.ord;
	grid[y + 1][x] = t.ord;
	if (t.id == 1 || t.id == 11 || t.id == 19)
		grid[y + 1][x + 1] = t.ord;
	if (t.id == 1)
		grid[y + 1][x + 2] = t.ord;
	if (t.id == 5 || t.id == 11 || t.id == 17)
		grid[y + 1][x - 1] = t.ord;
	if (t.id == 5)
		grid[y + 1][x - 2] = t.ord;
	else if (t.id == 17)
		grid[y + 2][x - 1] = t.ord;
	else if (t.id == 19)
		grid[y + 2][x + 1] = t.ord;
}

void	fee_write_sharp_2i(t_tetrimino t, char **grid, int x, int y)
{
	grid[y][x] = t.ord;
	grid[y][x + 1] = t.ord;
	if (t.id == 7 || t.id == 15 || t.id == 16)
		grid[y + 1][x + 1] = t.ord;
	if (t.id == 7)
		grid[y + 2][x + 1] = t.ord;
	if (t.id == 3 || t.id == 15 || t.id == 18)
		grid[y + 1][x] = t.ord;
	if (t.id == 3)
		grid[y + 2][x] = t.ord;
	if (t.id == 16)
		grid[y + 1][x + 2] = t.ord;
	else if (t.id == 18)
		grid[y + 1][x - 1] = t.ord;
}
