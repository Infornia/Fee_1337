int		tt_puterr(char *s, char *s2, int ret)
{
	ft_putstr("Error: ");
	if (s)
		ft_putendl(s);
	if (s2)
		ft_putendl(s2);
	return (ret);
}