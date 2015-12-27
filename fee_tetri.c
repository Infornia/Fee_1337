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
	//Vérifie que le tetrimino soit inscrivable à la position (x, y);
	//Retourne 1 si oui et 0 sinon
	(void)id;
	(void)grid;
	(void)x;
	(void)y;
	return (1);
}

void	fee_tetri_write(t_tetrimino t, char **grid, int x, int y)
{
	//Appelé après fee_tetri_write_check si celle-ci retourne 1
	//Inscrit le tetrimino à la position (x, y) dans la grille

	/*RAPPEL
	typedef struct  s_tetrimino
{
	int     id;		<--l'id du tetrimino
	char    ord;	<--Le charactère à imprimer pour ce tetrimino
}               t_tetrimino;*/

	ft_putchar(t.ord);
	(void)grid;
	(void)x;
	(void)y;
}

//Une suggestion pour eviter que la norme nous pète au nez avec les +25 lignes
/*static int	fee_tetri_read(char **t, int j, int i)
{
	while (j < 4 && !is_sharp(t[j][i]))
	{
		i = 0;
		while (i < 4 && !is_sharp(t[j][i]))
			i++;
		j++;
	}
	fee_tetri_read_bis(t, j , i); // qui contient ta série de if apres le if ((t[j][i]) == '#') 
}*/

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
			}
			++i;
		}
		++j;
	}
	return (tt_ps("Not a tetrimino", 0));
}

static void	alloc_final_grid(t_data *d, int size)
{
	int	i;

	i = -1;	
	d->grid = tt_malloc_tab(size * 4, size * 4);
	while (++i < size * 4)
			ft_memset(d->grid[i], '.', size * 4);
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
	    d->tetri[i].ord = i + 'A'; //Enregistre le char à imprimer pour l'ordre d'apparition des tetriminos
	    i++;
	}
	alloc_final_grid(d, i); // Aloue le nombre de tetrimino x la taille max d'un tetrimino (4 cases)
}