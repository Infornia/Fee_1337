/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_1337.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/12 19:50:48 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

void  open_close_file(char *file)
{
    int     fd; //Stockera le nombre "filedescriptor" du fichier ouvert assigné et retourné par open
    int     r; //Stockera le nombre de characteres lus retourné par Read
    char    buff[2048]; //Stockera les r characteres lus par Read
    
    fd = open(file, O_RDONLY); // Ouverture du fichier avec le flag "Read Only"->O_RDONLY (ou "lecture seule") + recupération du file descriptor
    
    r = read(fd, buff, sizeof(buff)); // Lecture du fichier avec read qui stock jusqu'à 2048 charactères lu dans le buffer "buff" et retourne le nombre de charactères lus dans r
    printf("Le Nom du fichier: %s\nLe fd: %i\nLa taille du buffer retournée par sizeof: %lu\nLe nombre de characteres lus: %i\n",
            file, fd, sizeof(buff), r);
    
    write(1, buff, r); //Ecriture sur la sortie standard (1) de "r" charactères du buffer "buff"
    
    close(fd); // Fermeture du filedescriptor correspondant au fichier
}

static void fee_init(t_data *d, char *file)
{
    d->file = file;
    d->nb_blocks = 0;
    d->tetri = (t_tetrimino *)malloc(sizeof(t_tetrimino) * 26);
}

void    fee_1337(char *file)
{
    t_data  *d;
    
    if (!(d = (t_data *)malloc(sizeof(t_data))))
        exit (tt_ps("Failed to malloc", 0));
    fee_init(d, file); // Initialise des variables de la struc de donnée
    fee_error(d); // Check les erreurs de fichiers
    fee_blocks_get(d); // Crée le Tableau char ***blocks
    fee_tetri(d); // Check les tetriminos et assigne son id
    fee_pattern(d); // Assemble les tetriminos à l'aide d'un pattern ou brut force
        //et appelle fee_tetri_write(d->tetri[i].id, c, x, y) pour remplir la grille d->grid
    //tt_printab(d->grid); // Imprime la grille finale
}