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
	brut_force(d, 0, 0, start);
	brut_force(d, 0, 0, 0);
	if (get_max(d, d->grid) > d->sqth)
	{
		newgrid(d, d->nb_blocks, -1);
		if (x > d->sqth && y > d->sqth)
		{
			if (start == d->nb_blocks - 1 && d->sqth++)
				fee_solve(d, 0, 0, 0);
			else
				fee_solve(d, x, y, ++start);
		}
		else if (x > d->sqth)
			fee_solve(d, x, ++y, start);
		else
			fee_solve(d, ++x, y, start);
	}
}
