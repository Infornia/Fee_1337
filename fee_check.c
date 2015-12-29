/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/12 19:50:48 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

int		fee_check_sharp_3j(int id, char **grid, int x, int y)
{
	if (grid[y][x] && grid[y + 1][x] && grid[y + 2][x] &&
		grid[y][x] == '.' && grid[y + 1][x] == '.' && grid[y + 2][x] == '.' )
	{
		if (id == 2 && grid[y + 2][x - 1] && grid[y + 2][x - 1] == '.' ) //id == 2
			return (1);
		if (id == 6 && grid[y + 2][x + 1] && grid[y + 2][x + 1] == '.' ) //id == 6
			return (1);
		if (id == 9 && grid[y + 1][x + 1] && grid[y + 1][x + 1] == '.' ) //id == 9
			return (1);
		if (id == 12 && grid[y + 1][x - 1] && grid[y + 1][x - 1] == '.' ) //id == 12
			return (1);
		if (id == 13 && grid[y + 3][x] && grid[y + 3][x] == '.' ) //id == 13
			return (1);
	}
	return(0);
}

int		fee_check_sharp_3i(int id, char **grid, int x, int y)
{
	if (grid[y][x] && grid[y][x + 1] && grid[y][x + 2] &&
		grid[y][x] == '.' && grid[y][x + 1] == '.' && grid[y][x + 2] == '.' )
	{
		if (id == 4 && grid[y + 1][x + 2] && grid[y + 1][x + 2] == '.' ) //id == 4
			return (1);
		if (id == 8 && grid[y + 1][x] && grid[y + 1][x] == '.' ) //id == 8
			return (1);
		if (id == 10 && grid[y + 1][x + 1] && grid[y + 1][x + 1] == '.' ) //id == 10
			return (1);
		if (id == 14 && grid[y][x + 3] && grid[y][x + 3] == '.' ) //id == 14
			return (1);
	}
	return(0);
}

int		fee_check_sharp_2j(int id, char **grid, int x, int y)
{
	if (grid[y][x] && grid[y + 1][x] && grid[y][x] == '.' && grid[y + 1][x] == '.')
	{
		if (id == 1 && grid[y + 1][x + 1] && grid[y + 1][x + 1] == '.' && grid[y + 1][x + 2] && grid[y + 1][x + 2] == '.') //id == 1
			return (1);
		if (id == 5 && grid[y + 1][x - 1] && grid[y + 1][x - 1] == '.' && grid[y + 1][x - 2] && grid[y + 1][x - 2] == '.') //id == 5
			return (1);
		if (id == 11 && grid[y + 1][x + 1] && grid[y + 1][x + 1] == '.' && grid[y + 1][x - 1] && grid[y + 1][x - 1] == '.') //id == 11
			return (1);
		if (id == 17 && grid[y + 1][x - 1] && grid[y + 1][x - 1] == '.' && grid[y + 2][x - 1] && grid[y + 2][x - 1] == '.') //id == 17
			return (1);	
		if (id == 19 && grid[y + 1][x + 1] && grid[y + 1][x + 1] == '.' && grid[y + 2][x + 1] && grid[y + 2][x + 1] == '.') //id == 19
			return (1);
	}
	return(0);
}
int		fee_check_sharp_2i(int id, char **grid, int x, int y)
{
	if (grid[y][x] && grid[y][x + 1] && grid[y][x] == '.' && grid[y][x + 1] == '.')
	{
		if (id == 7 && grid[y + 1][x + 1] && grid[y + 1][x + 1] == '.' && grid[y + 2][x + 1] && grid[y + 2][x + 1] == '.') //id == 7
			return (1);
		if (id == 15 && grid[y + 1][x + 1] && grid[y + 1][x + 1] == '.' && grid[y + 1][x] && grid[y + 1][x] == '.') //id == 15
			return (1);
		if (id == 16 && grid[y + 1][x + 1] && grid[y + 1][x + 1] == '.' && grid[y + 1][x + 2] && grid[y + 1][x + 2] == '.') //id == 16
			return (1);
		if (id == 18 && grid[y + 1][x] && grid[y + 1][x] == '.' && grid[y + 1][x - 1] && grid[y + 1][x - 1] == '.') //id == 18
			return (1);	
		if (id == 3 && grid[y + 1][x] && grid[y + 1][x] == '.' && grid[y][x + 2] && grid[y][x + 2] == '.') //id == 3
			return (1);
	}
	return(0);
}