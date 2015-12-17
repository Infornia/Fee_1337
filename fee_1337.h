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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct  s_tetrimino
{
    int id;
}               t_tetrimino;

typedef struct  s_data
{
    char        *file;
    char        **t;
    char        ***blocks;
    int         nb_blocks;
    char        **grid;
    
    t_tetrimino *tetri;
    
}               t_data;

/*
** fee_error.c
*/

int     fee_error(t_data *d);

/*
** fee_patern.c
*/

void    fee_patern(t_data d)

/*
** fee_tetri.c + helper
*/

void	fee_tetri(t_data *d);
int		two_sharpi(char **t, int i, int j);
int		two_sharpj(char **t, int i, int j);
int		three_sharpi(char **t, int i, int j);
int		three_sharpj(char **t, int i, int j);

/*
** fee_blocks_get.c
*/

void    fee_blocks_get(t_data *d);

/*
** tt_functions.c
*/

int     is_tetrichar(char c);
void    fee_blocks_del(t_data *d);

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
