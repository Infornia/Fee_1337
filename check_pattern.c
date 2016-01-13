/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/05 20:25:25 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

void	check_pattern(t_data *d, t_pattern p, int x, int y)
{
	int	i;

	i = d->nb_blocks + 1;
	while (--i > -1)
	{
		if (d->tetri[i].id == p.t1 && !d->tetri[i].used)
			p.id1 = i;
		else if (d->tetri[i].id == p.t2 && !d->tetri[i].used)
			p.id2 = i;
		else if (d->tetri[i].id == p.t3 && !d->tetri[i].used)
			p.id3 = i;
	}
	if (p.id1 >= 0 && p.id2 >= 0 && p.id3 >= 0
		&& fee_tetri_write_check(d->tetri[p.id2].id, d->grid, x + p.x2, y + p.y2)
		&& fee_tetri_write_check(d->tetri[p.id3].id, d->grid, x + p.x3, y  + p.y3))
	{
		fee_tetri_write(&d->tetri[p.id1], d->grid, x + p.x1, y + p.y1);
		fee_tetri_write(&d->tetri[p.id2], d->grid, x + p.x2, y + p.y2);
		fee_tetri_write(&d->tetri[p.id3], d->grid, x + p.x3, y + p.y3);
	}
}
