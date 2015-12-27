/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_tetri_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clapeyre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by clapeyre          #+#    #+#             */
/*   Updated: 2015/12/12 19:50:48 by clapeyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

int		two_sharpj(char **t, int i, int j) //8, 15, 1, 19
{
	if (t[j][i + 1] == '#') //8, 15, 18
	{
		if (t[j][i + 2] == '#')
			return (8); //8, LL /
		else if (t[j + 1][i + 1] == '#')
			return (15); //15, O /
		else if (t[j + 1][i - 1] == '#')
			return (18); //S /
	}
	else if (t[j + 1][i + 1] == '#') //1, 19, 11
	{
		if (t[j + 1][i + 2] == '#')
			return (1); //1, LR /
		else if (t[j + 2][i + 1] == '#')
			return (19); //19, ZL /
		if (t[j + 1][i - 1] == '#')
			return (11); //TD /
	}
	else if (t[j + 1][i - 1] == '#') //5, 17
	{
		if (t[j + 1][i - 2] == '#')
			return (5);//LR
		if (t[j + 2][i - 1] == '#')
			return (17);//ZR
	}
	exit (tt_ps("Not a form1", 0));
}

int		three_sharpj(char **t, int i, int j) //5, 3, 9, 13, 2, 12 
{
	if (t[j + 2][i + 1] == '#')
		return (6); // L 
	if (t[j][i + 1] == '#')
		return (3); //8, LU
	if (t[j + 1][i + 1] == '#')
		return (9); //9, T
	if (t[j + 3][i] == '#')
		return (13); //13, I
	if (t[j + 2][i - 1] == '#')
		return (2); //2, J
	if (t[j + 1][i - 1] == '#')
		return (12); // TR
	exit (tt_ps("Not a form2", 0));
}

int		two_sharpi(char **t, int i, int j)//7, 16
{
	if (t[j + 1][i + 1] == '#')
	{
		if (t[j + 2][i + 1] == '#')
			return (7); //7, LU
		if (t[j + 1][i + 2] == '#')
			return (16); //16 Z
	}

	exit (tt_ps("Not a form3", 0));
}

int		three_sharpi(char **t, int i, int j) //4, 10, 14
{
	if (t[j + 1][i + 2] == '#')
		return (4); //4, JL
	if (t[j + 1][i + 1] == '#')
		return (10); // T
		if (t[j][i + 3] == '#')
		return (14); //_
	exit (tt_ps("Not a form4", 0));
}
