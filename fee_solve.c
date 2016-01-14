#include "fee_1337.h"

static void brut_force(t_data *d, int x, int y, int i)
{
	int	stop;

	stop = i ? 1 : 0;
	while (i < d->nb_blocks)
	{
		if (!d->tetri[i].used)
		{
			while (!fee_tetri_write_check(d->tetri[i].id, d->grid, x, y))
				increment(d, &x, &y);
			fee_tetri_write(&d->tetri[i], d->grid, x, y);
		}
		x = 0;
		y = 0;
		++i;
		if (stop)
			return ;
	}
}

void	fee_solve(t_data *d, int x, int y, int start)
{
	limit_grid(d);
	brut_force(d, x, y, start);
	brut_force(d, 0, 0, 0);
	if (get_max(d, d->grid) > d->sqth)
	{
		if (start == 3)
			tt_printab(d->grid);
		printf("Maxi %i, maxj %i \n", d->maxi, d->maxj);
		newgrid(d, d->nb_blocks, -1);
		if (d->x > d->sqth && d->y > d->sqth)
		{
			if (start == d->nb_blocks - 1 && d->sqth++)
				fee_solve(d, 0, 0, 0);
			else
			{
				d->x = 0;
				d->y = 0;
				fee_solve(d, 0, 0, ++start);
			}
		}
		else if (d->x > d->sqth)
		{
			d->x = 0;
			fee_solve(d, 0, ++d->y, start);
		}
		else
			fee_solve(d, ++d->x, 0, start);
	}
}
