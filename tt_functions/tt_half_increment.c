void	tt_half_increment(int *x, int *y)
{
	if (*x == *y && ++(*x))
		*y = 0;
	else if (*x > *y)
		tt_swapnb(x, y);
	else if (*y > *x && ++(*x))
		tt_swapnb(x, y);
}