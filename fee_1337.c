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
	
	get_max(d, d->grid);
	tmp = tt_malloc_tab(d->maxj + 1, d->maxi + 1);
	j = -1;
	while (++j < d->maxj + 1)
		ft_strncpy(tmp[j], d->grid[j], d->maxi + 1);
	tt_del_tab(d->grid, d->nb_blocks * 4);
	d->grid = tmp;
}

void    fee_1337(char *file)
{
	t_data  *d;
	
	if (!(d = (t_data *)malloc(sizeof(t_data))))
		exit (tt_ps("Failed to malloc", 0));
	fee_init(d, file);
	fee_error(d);
	fee_blocks_get(d);
	fee_tetri(d);
	fee_pattern(d, 0, 0, -1);
	realloc_grid(d);
	tt_printab(d->grid);
}