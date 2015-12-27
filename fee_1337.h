/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_1337.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:49:36 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/12 19:51:02 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FEE_1337_H
# define FEE_1337_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define J_R    1
# define J_U    2
# define J_D    3
# define J_L    4
# define L_L    5
# define L_U    6
# define L_D    7
# define L_R    8
# define T_R    9
# define T_D    10
# define T_U    11
# define T_L    12
# define I_U    13
# define I_T    14
# define O_U    15
# define Z_U    16
# define Z_T    17
# define S_U    18
# define S_T    19

typedef struct  s_tetrimino
{
	int     id;
	char    ord;
}               t_tetrimino;

typedef struct	s_data
{
	char		*file;
	char		**t;
	char		***blocks;
	int			nb_blocks;
	char		**grid;
	
	t_tetrimino *tetri;
	
}               t_data;

/*
** fee_error.c
*/

int     fee_error(t_data *d);

/*
** fee_patern.c
*/

void    fee_pattern(t_data *d);

/*
** fee_tetri.c
*/

void	fee_tetri(t_data *d);
void	fee_tetri_write(t_tetrimino t, char **grid, int x, int y);
int		fee_tetri_write_check(int id, char **grid, int x, int y);

/*
** fee_tetri_help.c
*/

int		two_sharpi(char **t, int i, int j);
int		two_sharpj(char **t, int i, int j);
int		three_sharpi(char **t, int i, int j);
int		three_sharpj(char **t, int i, int j);

/*
** fee_blocks_get.c
*/

void    fee_blocks_get(t_data *d);

/*
** tt_utils.c
*/

int     is_tetrichar(char c);
void    fee_blocks_del(t_data *d);
int     is_sharp(char c);

/*
** tt_functions.c
*/


int		tt_ps(char *s, int ret);
int		tt_puterr(char *s, char *s2, int ret);
char    **tt_malloc_tab(int size_1, int size_2);
void	tt_printab(char **t);
void	tt_printabtab(char ***t);
void	tt_del_tab(char **t, int size);

/*
** others
*/

void    fee_1337(char *file);


#endif
