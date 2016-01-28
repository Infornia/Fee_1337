/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:10:16 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/28 21:37:25 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

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

void	tt_deltab(char **t, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(t[i++]);
	free(t);
}

void	tt_printab(char **t)
{
	int		i;

	i = 0;
	while (t && t[i])
		ft_putendl(t[i++]);
}

void	tt_printabtab(char ***t)
{
	int		i;

	i = 0;
	while (t[i])
		tt_printab(t[i++]);
}

int		tt_psel(char *s, int ret)
{
	ft_putendl(s);
	return (ret);
}

int		tt_ps(char *s, int ret)
{
	ft_putstr(s);
	return (ret);
}

int		tt_puterr(char *s, char *s2, int ret)
{
	ft_putstr("Error: ");
	if (s)
		ft_putendl(s);
	if (s2)
		ft_putendl(s2);
	return (ret);
}

int	tt_swpnb(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

float	tt_sqrt(int x)
{
	int s;

	s = 0;
	while (s * s < x)
		s++;
	return (s);
}

void	tt_half_increment(int *x, int *y)
{
	if (*x == *y && ++(*x))
		*y = 0;
	else if (*x > *y)
		tt_swpnb(x, y);
	else if (*y > *x && ++(*x))
		tt_swpnb(x, y);
}
