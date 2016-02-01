/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_tetri_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clapeyre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by clapeyre          #+#    #+#             */
/*   Updated: 2016/02/01 19:28:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

static int	pop_corn(char **t, int i, int j)
{
	if (t[j + 1][i - 2] == '#')
		return (L_L);
	if (t[j + 2][i - 1] == '#')
		return (Z_T);
	return (0);
}

int			two_sharpj(char **t, int i, int j)
{
	if (t[j][i + 1] == '#')
	{
		if (t[j][i + 2] == '#')
			return (L_R);
		else if (t[j + 1][i + 1] == '#')
			return (O_U);
		else if (t[j + 1][i - 1] == '#')
			return (S_U);
	}
	else if (t[j + 1][i + 1] == '#')
	{
		if (t[j + 1][i + 2] == '#')
			return (J_R);
		else if (t[j + 2][i + 1] == '#')
			return (S_T);
		if (t[j + 1][i - 1] == '#')
			return (T_U);
	}
	else if (t[j + 1][i - 1] == '#')
		return (pop_corn(t, i, j));
	exit(tt_ps(ERR, 0));
}

int			three_sharpj(char **t, int i, int j)
{
	if (t[j + 2][i + 1] == '#')
		return (L_U);
	if (t[j][i + 1] == '#')
		return (J_D);
	if (t[j + 1][i + 1] == '#')
		return (T_R);
	if (t[j + 3][i] == '#')
		return (I_U);
	if (t[j + 2][i - 1] == '#')
		return (J_U);
	if (t[j + 1][i - 1] == '#')
		return (T_L);
	exit(tt_ps(ERR, 0));
}

int			two_sharpi(char **t, int i, int j)
{
	if (t[j + 1][i + 1] == '#')
	{
		if (t[j + 2][i + 1] == '#')
			return (L_D);
		if (t[j + 1][i + 2] == '#')
			return (Z_U);
	}
	exit(tt_ps(ERR, 0));
}

int			three_sharpi(char **t, int i, int j)
{
	if (t[j + 1][i + 2] == '#')
		return (J_L);
	if (t[j + 1][i + 1] == '#')
		return (T_D);
	if (t[j][i + 3] == '#')
		return (I_T);
	exit(tt_ps(ERR, 0));
}
