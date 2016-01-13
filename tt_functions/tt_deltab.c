void	tt_del_tab(char **t, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(t[i++]);
	free(t);
}