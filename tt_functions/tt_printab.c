void	tt_printab(char **t)
{
	int		i;

	i = 0;
	while (t && t[i])
		ft_putendl(t[i++]);
}