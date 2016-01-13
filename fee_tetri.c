/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/05 21:06:17 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

int		fee_tetri_write_check(int id, char **grid, int x, int y)
{
	if (id == J_U || id == L_U || id == T_R || id == T_L || id == I_U)
		return (fee_check_sharp_3j(id, grid, x, y));
	if (id == J_L || id == L_R || id == T_D || id == I_T)
		return (fee_check_sharp_3i(id, grid, x, y));
	if (id == J_R || id == L_L || id == T_U || id == Z_T || id == S_T)
		return (fee_check_sharp_2j(id, grid, x, y));
	if (id == L_D || id == O_U || id == Z_U || id == S_U || id == J_D)
		return (fee_check_sharp_2i(id, grid, x, y));
	return (0);
}

void	fee_tetri_write(t_tetrimino *yeah, char **grid, int x, int y)
{
	t_tetrimino t;
	
	yeah->used = 1;
	t = *yeah;
	if (t.id == J_U || t.id == L_U || t.id == T_R || t.id == T_L || t.id == I_U)
		(fee_write_sharp_3j(t, grid, x, y));
	if (t.id == J_L || t.id == L_R || t.id == T_D || t.id == I_T)
		(fee_write_sharp_3i(t, grid, x, y));
	if (t.id == J_R || t.id == L_L || t.id == T_U || t.id == Z_T || t.id == S_T)
		(fee_write_sharp_2j(t, grid, x, y));
	if (t.id == L_D || t.id == O_U || t.id == Z_U || t.id == S_U || t.id == J_D)
		(fee_write_sharp_2i(t, grid, x, y));
}

static int	fee_tetri_read_bis(char **t, int i, int j)
{
	if (t[j+1][i] == '#') 
	{
		if (t[j+2][i] == '#')
			return (three_sharpj(t, i, j));
		return (two_sharpj(t, i, j));
	}
	else if (t[j][i+1] == '#')
	{
		if (t[j][i+2] == '#')
			return (three_sharpi(t, i, j));
		return (two_sharpi(t, i, j));
	}
	exit(tt_ps(ERR, 0));
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
	exit(tt_ps(ERR, 0));
}

void	fee_tetri(t_data *d)
{
	int form;
	int i;

	i = -1;
	while (++i < d->nb_blocks)
	{
		form = fee_tetri_read(d->blocks[i]);
		d->tetri[i].id = form;
		d->tetri[i].used = 0;
		d->tetri[i].ord = i + 'A';
	}
	alloc_grid(d, i);
}