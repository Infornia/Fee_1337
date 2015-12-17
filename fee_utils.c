/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:48:08 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/12 18:42:13 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

int     is_tetrichar(char c)
{
    if (c == '.' || c == '#')
        return (1);
    return (0);
}

void    fee_blocks_del(t_data *d)
{
    int i;
    
    i = 0;
    while (i < d->nb_blocks)
        tt_del_tab(d->blocks[i], 5);
    free(d->blocks);
}