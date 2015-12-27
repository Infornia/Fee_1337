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
    //Parcours les tetriminos restants un par un et les envois à tetri_check et write
    //tant qu'il en reste à poser
    int i;
    int x;
    int y;
    
    i = 0;
    x = 0;
    y = 0;
    while (i < d->nb_blocks)
    {
        if (fee_tetri_write_check(d->tetri[i].id, d->grid, x, y))
            fee_tetri_write(d->tetri[i++], d->grid, x, y);
    }
}

void    fee_pattern(t_data *d)
{
    
    brut_force(d); 
    return ;
}