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

static t_tetri	ct(int id, int x, int y)
{
	t_tetri t;
	
	t.t = id;
	t.x = x;
	t.y = y;
	return (t);
}

t_pattern	create_pattern(t_tetri t1, t_tetri t2, t_tetri t3)
{
	t_pattern p;
	
	p.t1 = t1.t;
	p.t2 = t2.t;
	p.t3 = t3.t;
	p.id1 = 0;
	p.id2 = 0;
	p.id3 = 0;
	p.x1 = t1.x;
	p.x2 = t2.x;
	p.x3 = t3.x;
	p.y1 = t1.y;
	p.y2 = t2.y;
	p.y3 = t3.y;
	return (p);
}

void	create_patterns(t_data *d)
{
	d->p[0] = create_pattern(ct(J_L, 0, 0), ct(Z_U, 0, 1), ct(J_R, 0, 2));
	d->p[1] = create_pattern(ct(J_D, 0, 0), ct(Z_T, 2, 0), ct(J_U, 3, 0));
	d->p[2] = create_pattern(ct(L_R, 0, 0), ct(S_U, 1, 1), ct(L_L, 2, 3));
	d->p[3] = create_pattern(ct(L_U, 0, 0), ct(S_T, 1, 0), ct(L_D, 2, 0));
}

static void brut_force(t_data *d, int x, int y, int i)
{
	while (i < d->nb_blocks)
	{
		if (d->tetri[i].used)
		{
			i++;
			continue ;
		}
		if (!d->tetri[i].used
			&& fee_tetri_write_check(d->tetri[i].id, d->grid, x, y))
		{
			fee_tetri_write(&d->tetri[i++], d->grid, x, y);
			y /= 3;
			x /= 3;
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
	int i;
	int x;
	int y;
	int k;
	
	x = 0;
	y = 0;
	k = -1;
	while (++k < NB_PATTERNS)
	{
		i = 0;
		while (i < d->nb_blocks && d->tetri[i].id != d->p[k].t1)
			i++;
		while (!fee_tetri_write_check(d->p[k].t1, d->grid, x, y))
		{
			if (x == y && ++x)
				y = 0;
			else if (x > y)
				tt_swapnb(&x, &y);
			else if (y > x && ++x)
				tt_swapnb(&x, &y);
		}
		check_pattern(d, d->p[k], x, y);
	}
	brut_force(d, 0, 0, 0); 
	return ;
}