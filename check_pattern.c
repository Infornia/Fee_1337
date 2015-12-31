/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/12 19:50:48 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fee_1337.h"

/*void	check_pattern_1(t_data *d, int x, int y, int i)
{
	int pattern1;
	int pattern2;
	int pattern3;
	
	pattern1 = 0;
	pattern2 = 0;
	pattern3 = 0;
	while (i < d->nb_blocks)
	{
		if (d->tetri[i].id == J_L && !d->tetri[i].used)
			pattern1 = i;
		if (d->tetri[i].id == Z_U && !d->tetri[i].used)
			pattern2 = i;
		if (d->tetri[i].id == J_R && !d->tetri[i].used)
			pattern3 = i;
		i++;
	}
	if (pattern1 && fee_tetri_write_check(d->tetri[pattern1].id , d->grid, x, y) && pattern2 && pattern3)
	{
		fee_tetri_write(&d->tetri[pattern1], d->grid, x, y);
		fee_tetri_write(&d->tetri[pattern2], d->grid, x, y + 1);
		fee_tetri_write(&d->tetri[pattern3], d->grid, x, y + 2);
	}
}
*/

void	check_pattern(t_data *d, t_pattern p, int x, int y)
{
	int	i;
	
	i = 0;
	while (i < d->nb_blocks)
	{
		if (d->tetri[i].id == p.t1 && !d->tetri[i].used)
			p.id1 = i;
		else if (d->tetri[i].id == p.t2 && !d->tetri[i].used)
			p.id2 = i;
		else if (d->tetri[i].id == p.t3 && !d->tetri[i].used)
			p.id3 = i;
		i++;
	}
	if (p.id1 && fee_tetri_write_check(d->tetri[p.id1].id , d->grid, x, y) && p.id2 && p.id3)
	{
		fee_tetri_write(&d->tetri[p.id1], d->grid, x + p.x1, y + p.y1);
		fee_tetri_write(&d->tetri[p.id2], d->grid, x + p.x2, y + p.y2);
		fee_tetri_write(&d->tetri[p.id3], d->grid, x + p.x3, y + p.y3);
	}
}