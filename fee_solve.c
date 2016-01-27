#include "fee_1337.h"

static void simple_brut(t_data *d, int x, int y, int i)
{
		if (!d->tetri[i].used)
		{
			while (!fee_tetri_write_check(d->tetri[i].id, d->grid, x, y))
				increment(d, &x, &y);
			fee_tetri_write(&d->tetri[i], d->grid, x, y);
		}
		return ;
}

static int print(t_data *d, const int *v)
{
	int i;

	i = -1;
//	printf("%i, %i, %i\n", x, y, d->sqth);
	if (v != 0)
		while (++i < d->nb_blocks)
			simple_brut(d, 0, 0, v[i] - 1);
//	if (y == 2)
//		tt_printab(d->grid);
	if (get_max(d, d->grid) > d->sqth)
	{
		newgrid(d, d->nb_blocks, -1);
		limit_grid(d);
		return (0);
	}
	return (1);
}

static void permutation(t_data *d, int *Value, int k)
{
	static int	level = -1;
	int			i;

	if (d->stop)
		return ;
	i = -1;
	Value[k] = ++level;
	if (level == d->nb_blocks)
		d->stop = print(d, Value);
	else
	{
		while (++i < d->nb_blocks)
			if (Value[i] == 0)
				permutation(d, Value, i);
	}
	--level;
	Value[k] = 0;
}

void	fee_solve(t_data *d)
{
	int i;
	int tab[d->nb_blocks];

	i = -1;
	while (++i < d->nb_blocks)
		tab[i] = 0;
	limit_grid(d);
	permutation(d, tab, 0);
	if (d->maxj > d->sqth || d->maxi > d->sqth)
	{
		d->sqth++;
		newgrid(d, d->nb_blocks, -1);
		limit_grid(d);
		fee_solve(d);
	}
}
