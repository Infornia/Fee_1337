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

int		two_sharpj(char **t, int i, int j) //3, 7, 15, 16, 18
{
	if (t[j][i + 1] == '#') //3, 15, 18
	{
		if (t[j][i + 2] == '#')
			return (2); //3, JU /
		else if (t[j + 1][i + 1] == '#')
			return (14); //15, O /
		else if (t[j - 1][i + 1] == '#')
			return (17); //18, SD /
	}
	else if (t[j + 1][i + 1] == '#') //7, 16
	{
		if (t[j + 1][i + 2] == '#')
			return (6); //7, LU /
		else if (t[j + 2][i + 1] == '#')
			return (15); //16, ZD /
	}
	exit (tt_ps("Not a form1", 0));
}


/*typedef struct	s_luna
{
	int		huile;
	char	*bigmac;
	char	**fastfood;
	float	*mayonnaise;
	double	cheese;
}					t_luna;
//char	*feed(t_luna luna);
char	*feed(t_luna luna)
{
	luna->fastfood[0] = "boule de gras";
	luna->fastfood[1] = "Bide énorme";
	luna->fastfood[2] = "Bourelets Xtrem";
	luna->fastfood[3] = "RDV Mac DO";
	luna->fastfood[4] = "Pas manger Vegan";
	if (luna->huile == -1)
		return ("famine");
		
}*/

int		three_sharpj(char **t, int i, int j) //4, 8, 10, 14
{
	if (t[j + 2][i + 1] == '#')
		return (3); //4, JL /
	if (t[j][i + 1] == '#')
		return (7); //8, LR
	if (t[j + 1][i + 1] == '#')
		return (9); //10, T
	if (t[j + 3][i] == '#')
		return (13); //14, IL
	exit (tt_ps("Not a form2", 0));
}

int		two_sharpi(char **t, int i, int j)//1, 5, 11, 17, 19
{
	if (t[j + 1][i + 1] == '#') //1, 11, 19
	{
		if (t[j + 2][i + 1] == '#')
			return (0); //1, JR
		if (t[j - 1][i + 1] == '#')
			return (10); //11, TU 
		if (t[j + 1][i + 3] == '#')
			return (18); //19, S penche
	}
	else if(t[j - 1][i + 1] == '#') //5, 17
	{
		if (t[j - 2][i + 1] == '#')
			return (4); //5, LL 
		if (t[j - 1][i + 2] == '#')
			return (16); //17, ZL
	}
	exit (tt_ps("Not a form3", 0));
}

int		three_sharpi(char **t, int i, int j) //2, 6, 9, 12, 13
{

	if (t[j - 1][i + 2] == '#')
		return (1); //, J 
	if (t[j + 1][i + 2] == '#')
		return (5); //6, L
	if (t[j + 1][i + 1] == '#')
		return (8); //9, TL R
	if (t[j - 1][i + 1] == '#')
		return (11); //12, TL R
	if (t[j][i + 3] == '#')
		return (12); //13, |
	exit (tt_ps("Not a form4", 0));
}
