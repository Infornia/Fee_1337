#include "fee_1337.h"

static void brut_force(t_data *d, int x, int y, int i)
{
	while (++i < d->nb_blocks)
	{
		while (!fee_tetri_write_check(d->tetri[i].id, d->grid, x, y))
			increment(d, &x, &y);
		if (!d->tetri[i].used)
			fee_tetri_write(&d->tetri[i], d->grid, x, y);
	}
}

void	fee_solve(t_data *d, int x, int y)
{
	limit_grid(d);
	brut_force(d, x, y, -1);
	if (get_max(d, d->grid) > d->sqth)
	{
		newgrid(d, d->nb_blocks, -1);
		if (d->x > d->sqth && d->y > d->sqth && d->sqth++)
			fee_solve(d, 0, 0);
		else if (d->x > d->sqth)
		{
			d->x = 0;
			fee_solve(d, 0, ++d->y);
		}
		else
			fee_solve(d, ++d->x, 0);
	}
}