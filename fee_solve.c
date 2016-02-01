#include "fee_1337.h"

static void brut_force(t_data *d, int x, int y, int i)
{
	int tmpx;
	int tmpy;

	tmpx = 0;
	tmpy = 0;
	simple_brut(d, x, y, 0);
	while (++i < d->nb_blocks)
	{
		if (!d->tetri[i].used)
		{
			while (!fee_tetri_write_check(d->tetri[i].id, d->grid, tmpx, tmpy))
				increment(d, &tmpx, &tmpy);
			fee_tetri_write(&d->tetri[i], d->grid, tmpx, tmpy);
		}
	}
	if (get_max(d, d->grid) < d->sqth)
		return ;
	newgrid(d, d->nb_blocks, -1);
	limit_grid(d);
	increment(d, &x, &y);
	if (x <= d->sqth &&  y < d->sqth)
		brut_force(d, x, y, 0);
}

static int print(t_data *d, const int *v)
{
	int i;

	i = -1;
	if (v != 0)
		while (++i < d->nb_blocks)
			simple_brut(d, 0, 0, v[i] - 1);
	if (get_max(d, d->grid) <= d->sqth)
		return (1);
	newgrid(d, d->nb_blocks, -1);
	limit_grid(d);
	return (0);
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

static int	solve_it(t_data *d, int mode)
{
	int i;
	int tab[d->nb_blocks];

	i = -1;
	newgrid(d, d->nb_blocks, -1);
	limit_grid(d);
	while (++i < d->nb_blocks)
		tab[i] = 0;
	!mode ? permutation(d, tab, 0) : brut_force(d, 0, 0, -1);
	if (d->maxj <= d->sqth && d->maxi <= d->sqth)
		return (1);
	return (0);
}

void	fee_solve(t_data *d)
{
	while (22)
	{
		if (solve_it(d, 0))
			break ;
		if (solve_it(d, 1))
			break ;
		d->sqth++;
	}
}
