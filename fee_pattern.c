/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_pattern.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/12 19:50:48 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

static void brut_force(t_data *d)
{
	int i;
	int x;
	int y;
	int k;
	
	i = 0;
	x = 0;
	y = 0;
	k = 0;
	while (i < d->nb_blocks && d->old_x < d->nb_blocks)
	{
		if (fee_tetri_write_check(d->tetri[i].id, d->grid, x, y))
		{
			fee_tetri_write(d->tetri[i++], d->grid, x, y);
			if (!(++k % 3))
			{
				y /= 2;
				x /= 2;
			}
		}
		if (x == y && ++x)
			y = 0;
		else if (x > y)
			tt_swapnb(&x, &y);
		else if (y > x && ++x)
			tt_swapnb(&x, &y);
		//printf("(%i, %i)\n", x, y);
	}
}

void    fee_pattern(t_data *d)
{
	
	brut_force(d); 
	return ;
}