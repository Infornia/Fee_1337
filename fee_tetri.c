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

int		fee_tetri_write_check(int id, char **grid, int x, int y)
{
	if (id == 2 || id == 6 || id == 9 || id == 12 || id == 13)
		return (fee_check_sharp_3j(id, grid, x, y));
	if (id == 4 || id == 8 || id == 10 || id == 14)
		return (fee_check_sharp_3i(id, grid, x, y));
	if (id == 1 || id == 5 || id == 11 || id == 17 || id == 19)
		return (fee_check_sharp_2j(id, grid, x, y));
	if (id == 7 || id == 15 || id == 16 || id == 18 || id == 3)
		return (fee_check_sharp_2i(id, grid, x, y));
	return (0);
}

void	fee_tetri_write(t_tetrimino *yeah, char **grid, int x, int y)
{
	t_tetrimino t;
	
	yeah->used = 1;
	t = *yeah;
	if (t.id == 2 || t.id == 6 || t.id == 9 || t.id == 12 || t.id == 13)
		(fee_write_sharp_3j(t, grid, x, y));
	if (t.id == 4 || t.id == 8 || t.id == 10 || t.id == 14)
		(fee_write_sharp_3i(t, grid, x, y));
	if (t.id == 1 || t.id == 5 || t.id == 11 || t.id == 17 || t.id == 19)
		(fee_write_sharp_2j(t, grid, x, y));
	if (t.id == 7 || t.id == 15 || t.id == 16 || t.id == 18 || t.id == 3)
		(fee_write_sharp_2i(t, grid, x, y));
}

static int	fee_tetri_read_bis(char **t, int i, int j)
{
	if (t[j+1][i] == '#') 
	{
		if (t[j+2][i] == '#') //4, 8, 10, 14
			return (three_sharpj(t, i, j));			
		return (two_sharpj(t, i, j));			
	}
	else if (t[j][i+1] == '#') //1, 5, 11, 17, 19
	{
		if (t[j][i+2] == '#') //2, 6, 9, 12, 13
			return (three_sharpi(t, i, j));			
		return (two_sharpi(t, i, j));			
	}
	return (0);
}

static int	fee_tetri_read(char **t)
{
	int i;
	int j;

	j = 0;
	//tt_printab(t);
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if ((t[j][i]) == '#')
				return(fee_tetri_read_bis(t, i, j));
			i++;
		}
		++j;
	}
	return (tt_ps("Not a tetrimino", 0));
}

static void	alloc_final_grid(t_data *d, int size)
{
	int	i;

	i = -1;
	size *= 4;
	d->grid = tt_malloc_tab(size, size);
	while (++i < size)
			ft_memset(d->grid[i], '.', size);
}

void	fee_tetri(t_data *d)
{
	int form;
	int i;
	
	i = 0;
	while (i < d->nb_blocks)
	{
	    form = fee_tetri_read(d->blocks[i]);
	    d->tetri[i].id = form;
	    d->tetri[i].used = 0;
	    d->tetri[i].ord = i + 'A';
	    i++;
	}
	alloc_final_grid(d, i);
}