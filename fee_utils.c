/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:48:08 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/14 20:03:28 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

int		is_tetrichar(char c)
{
	if (c == '.' || c == '#')
		return (1);
	return (0);
}

void	increment(t_data *d, int *x, int *y)
{
	if (*x < d->sqth)
		(*x)++;
	else
	{
		(*x) = 0;
		(*y)++;
	}
}

void	fee_blocks_del(t_data *d)
{
	int i;

	i = 0;
	while (i < d->nb_blocks)
		tt_deltab(d->blocks[i], 5);
	free(d->blocks);
}

int		get_max(t_data *d, char **t)
{
	int		i;
	int		j;
	int		cmp;

	j = -1;
	cmp = d->nb_blocks * 4;
	d->maxi = 0;
	d->maxj = 0;
	while (++j < cmp)
	{
		i = -1;
		while (++i < cmp)
		{
			if (ft_isupper(t[j][i]))
			{
				d->maxi = d->maxi < i ? i : d->maxi;
				d->maxj = d->maxj < j ? j : d->maxj;
			}
		}
	}
	return (d->maxi < d->maxj ? d->maxj : d->maxi);
}
