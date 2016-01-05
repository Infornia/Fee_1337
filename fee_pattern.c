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
	p.id1 = -1;
	p.id2 = -1;
	p.id3 = -1;
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
	d->p[0] = create_pattern(ct(J_L, 0, 0), ct(Z_U, 0, 1), ct(J_R, 0, 2));//jzj
	d->p[1] = create_pattern(ct(J_D, 0, 0), ct(Z_T, 2, 0), ct(J_U, 3, 0));//jzj
	d->p[2] = create_pattern(ct(L_R, 0, 0), ct(S_U, 1, 1), ct(L_L, 2, 2));//lzl
	d->p[3] = create_pattern(ct(L_U, 0, 0), ct(S_T, 1, 0), ct(L_D, 2, 0));//lzl
	d->p[4] = create_pattern(ct(S_T, 0, 0), ct(L_D, 0, 1), ct(J_R, 2, 0));//jzl
	d->p[5] = create_pattern(ct(J_D, 0, 0), ct(S_U, 0, 2), ct(L_L, 1, 3));//jzl
	d->p[6] = create_pattern(ct(J_L, 0, 0), ct(L_U, 1, 0), ct(S_T, 1, 1));//jzl
	d->p[7] = create_pattern(ct(Z_U, 0, 0), ct(J_R, 1, 0), ct(L_D, 0, 2));//jzl
	d->p[8] = create_pattern(ct(J_D, 0, 0), ct(Z_T, 0, 2), ct(L_L, 2, 2));//lsj
	d->p[9] = create_pattern(ct(L_U, 0, 0), ct(J_L, 0, 1), ct(Z_U, 1, 1));//lsj
	d->p[10] = create_pattern(ct(L_R, 0, 0), ct(Z_T, 1, 1), ct(J_U, 1, 2));//lsj
	d->p[11] = create_pattern(ct(L_U, 0, 0), ct(J_L, 0, 1), ct(Z_U, 1, 1));//lsj
	d->p[12] = create_pattern(ct(L_R, 0, 0), ct(O_U, 1, 1), ct(J_R, 2, 0));//jol
	d->p[13] = create_pattern(ct(J_D, 0, 0), ct(O_U, 1, 1), ct(J_D, 0, 2));//jol
	d->p[14] = create_pattern(ct(J_L, 0, 0), ct(O_U, 1, 0), ct(L_L, 3, 0));//jol
	d->p[15] = create_pattern(ct(L_U, 0, 0), ct(O_U, 0, 1), ct(J_U, 0, 3));//jol
	d->p[16] = create_pattern(ct(T_D, 0, 0), ct(L_U, 1, 0), ct(T_L, 1, 2));//ltt
	d->p[17] = create_pattern(ct(T_R, 0, 0), ct(T_D, 0, 1), ct(L_L, 1, 3));//ltt
	d->p[18] = create_pattern(ct(T_R, 0, 0), ct(T_U, 1, 2), ct(L_D, 0, 1));//ltt
	d->p[19] = create_pattern(ct(L_R, 0, 0), ct(T_U, 1, 2), ct(T_L, 0, 3));//ltt 
	d->p[20] = create_pattern(ct(T_D, 0, 0), ct(T_R, 1, 0), ct(J_U, 1, 2));//jtt
	d->p[21] = create_pattern(ct(T_R, 0, 0), ct(T_U, 1, 2), ct(J_L, 0, 1));//jtt
	d->p[22] = create_pattern(ct(J_D, 0, 0), ct(T_L, 0, 2), ct(T_U, 2, 1));//jtt
	d->p[23] = create_pattern(ct(T_D, 0, 0), ct(T_L, 0, 3), ct(J_R, 1, 0));//jtt
	d->p[24] = create_pattern(ct(L_R, 0, 0), ct(L_D, 1, 1), ct(O_U, 2, 0));//oll
	d->p[25] = create_pattern(ct(L_U, 0, 0), ct(L_R, 0, 1), ct(O_U, 1, 2));//oll
	d->p[26] = create_pattern(ct(L_U, 0, 0), ct(L_L, 2, 2), ct(O_U, 0, 1));//oll
	d->p[27] = create_pattern(ct(L_D, 0, 2), ct(L_L, 1, 2), ct(O_U, 0, 0));//oll
	d->p[28] = create_pattern(ct(J_L, 0, 0), ct(J_D, 1, 0), ct(O_U, 2, 1));//ojj
	d->p[29] = create_pattern(ct(J_D, 0, 0), ct(J_R, 1, 1), ct(O_U, 0, 2));//ojj
	d->p[30] = create_pattern(ct(J_U, 0, 2), ct(J_R, 2, 0), ct(O_U, 0, 0));//ojj
	d->p[31] = create_pattern(ct(J_L, 0, 0), ct(J_U, 0, 3), ct(O_U, 1, 0));//ojj
}

static void brut_force(t_data *d, int x, int y, int i)
{
	while (i < d->nb_blocks)
	{
		while (!fee_tetri_write_check(d->tetri[i].id, d->grid, x, y))
		{
			if (x == y && ++x)
				y = 0;
			else if (x > y)
				tt_swapnb(&x, &y);
			else if (y > x && ++x)
				tt_swapnb(&x, &y);
		}
		if (!d->tetri[i].used)
			fee_tetri_write(&d->tetri[i], d->grid, x, y);
		y /= 2;
		x /= 2;
		i++;
	}
}

void    fee_pattern(t_data *d, int x, int y, int k)
{
	int i;

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