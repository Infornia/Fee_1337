#include "fee_1337.h"

void	alloc_grid(t_data *d, int size)
{
	int	i;

	i = -1;
	size *= 4;
	d->grid = tt_malloc_tab(size, size);
	while (++i < size)
		ft_memset(d->grid[i], '.', size);
}

void	newgrid(t_data *d, int size, int i)
{
	size *= 4;
	while (++i < size)
		ft_memset(d->grid[i], '.', size);
	i = -1;
	while (++i < d->nb_blocks)
		d->tetri[i].used = 0;
}

void	limit_grid(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->sqth)
		ft_memset(&d->grid[i][d->sqth], '2', 1);
	ft_memset(d->grid[d->sqth], '2', d->sqth + 1);
}

void    realloc_grid(t_data *d)
{
	int		j;
	int		max;
	char	**tmp;
	
	max = get_max(d, d->grid);
	tmp = tt_malloc_tab(max + 1, max + 1);
	j = -1;
	while (++j < max + 1)
		ft_strncpy(tmp[j], d->grid[j], max + 1);
	tt_deltab(d->grid, d->nb_blocks * 4);
	d->grid = tmp;
}
