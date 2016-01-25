/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_1337.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/25 23:17:28 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

static void fee_theos(t_data *d)
{
	int i;
	int found;

	i = -1;
	found = 0;
	while (++i < d->nb_blocks)
		if (d->tetri[i].id == I_U || d->tetri[i].id == I_T)
			found++;
	d->sqth = (tt_sqrt(4 * (d->nb_blocks + 1)) + 0.5);
	if (d->sqth < 4 && found)
		d->sqth = 4;
}
static void fee_init(t_data *d, char *file)
{
	d->file = file;
	d->nb_blocks = 0;
	d->stop = 0;
	d->tetri = (t_tetrimino *)malloc(sizeof(t_tetrimino) * 26);
	d->p = (t_pattern *)malloc(sizeof(t_pattern) * NB_PATTERNS);
}

void    fee_1337(char *file)
{
	t_data  *d;
	
	if (!(d = (t_data *)malloc(sizeof(t_data))))
		exit (tt_ps(ERR, 0));
	fee_init(d, file);
	fee_error(d);
	fee_blocks_get(d);
	fee_tetri(d);
	fee_theos(d);
	fee_solve(d);
	realloc_grid(d);
	tt_printab(d->grid);
}
