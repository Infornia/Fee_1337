void	tt_printabtab(char ***t)
{
	int		i;

	i = 0;
	while (t[i])
		tt_printab(t[i++]);
}