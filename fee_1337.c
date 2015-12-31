/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_1337.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/12 19:50:48 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

static void fee_init(t_data *d, char *file)
{
	d->file = file;
	d->nb_blocks = 0;
	d->tetri = (t_tetrimino *)malloc(sizeof(t_tetrimino) * 26);
	d->maxi = 0;
	d->maxj = 0;
	d->p = (t_pattern *)malloc(sizeof(t_pattern) * NB_PATTERNS);
	create_patterns(d);
}

static void realloc_grid(t_data *d)
{
	int		j;
	char	**tmp;
	
	tmp = tt_malloc_tab(d->maxj + 1, d->maxi + 1);
	j = -1;
	while (++j < d->maxj + 1)
		ft_strncpy(tmp[j], d->grid[j], d->maxi + 1);
	tt_del_tab(d->grid, d->nb_blocks * 4);
	d->grid = tmp;
}

static void	get_max(t_data *d, char **t)
{
	int		i;
	int		j;
	int		cmp;
	
	j = -1;
	cmp = d->nb_blocks * 4;
	while (++j < cmp)
	{
		i = -1;
		while (++i < cmp)
		{
			if (t[j][i] != '.')
			{
				d->maxi = d->maxi < i ? i : d->maxi;
				d->maxj = d->maxj < j ? j : d->maxj;
			}
		}
	}
}

void    fee_1337(char *file)
{
	t_data  *d;
	
	if (!(d = (t_data *)malloc(sizeof(t_data))))
		exit (tt_ps("Failed to malloc", 0));
	fee_init(d, file); // Initialise des variables de la struc de donnée
	fee_error(d); // Check les erreurs de fichiers
	fee_blocks_get(d); // Crée le Tableau char ***blocks
	fee_tetri(d); // Check les tetriminos et assigne son id
	fee_pattern(d); // Assemble les tetriminos à l'aide d'un pattern ou brut force
		//et appelle fee_tetri_write(d->tetri[i].id, c, x, y) pour remplir la grille d->grid
	get_max(d, d->grid);
	realloc_grid(d);
	tt_printab(d->grid); // Imprime la grille finale
}