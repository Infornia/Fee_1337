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



//coucou BWAAHhHhhhhhHH Caca qui fait du surf
//#Troplafrappe, professionnel++;
//piqu nik sur les bord de Seine avec une corde :)
// if (luna(bigmac, big tasty))
//		grossir++;
//return ("grosse boule de graisse")

static void	alloc_final_grid(t_data *d, int size)
{
	int	i;

	i = -1;	
	d->grid = tt_malloc_tab(size * 4, size * 4);
	while (++i < size * 4)
			ft_memset(d->grid[i], '.', size * 4);
}

static int	fee_tetri_read(char **t)
{
	int i;
	int j;

	j = 0;
	ft_putendl("Je check un BLOCK LOLMDR");
	//tt_printab(t);
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if ((t[j][i]) == '#')
			{
				if (t[j+1][i] == '#') //3, 7, 15, 16, 18
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
			}
			++i;
		}
		++j;
	}
	return (tt_ps("Not a tetrimino", 0));
}

void	fee_tetri(t_data *d)
{
		
	int form;
	int i;
	
	i = 0;
	while (i < d->nb_blocks)
	{
	    form = fee_tetri_read(d->blocks[i]);
	    printf("Le retour de read: %i\n\n", form);
	    d->tetri[i].id = form;
	    i++;
	}
	
	alloc_final_grid(d, i);
}