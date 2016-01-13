char	**tt_malloc_tab(int size_1, int size_2)
{
	char	**ret;
	int			i;

	ret = (char **)malloc(sizeof(char *) * (size_1 + 1));
	i = -1;
	while (++i < size_1)
		ret[i] = ft_strnew(size_2);
	return (ret);
}