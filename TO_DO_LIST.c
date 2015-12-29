# Scinder fee_tetri_read en 2
# Ecrire fee_tetri_write_check
# Ecrire fee_tetri_write


coucou BWAAHhHhhhhhHH Caca qui fait du surf
#Troplafrappe, professionnel++;
piqu nik sur les bord de Seine avec une corde :)

if (luna(bigmac, big tasty))
		grossir++;
return ("grosse boule de graisse")

typedef struct	s_luna
{
	int		huile;
	char	*bigmac;
	char	**fastfood;
	float	*mayonnaise;
	double	cheese;
}					t_luna;
char	*feed(t_luna luna);
char	*feed(t_luna luna)
{
	luna->fastfood[0] = "boule de gras";
	luna->fastfood[1] = "Bide énorme";
	luna->fastfood[2] = "Bourelets Xtrem";
	luna->fastfood[3] = "RDV Mac DO";
	luna->fastfood[4] = "Pas manger Vegan";
	if (luna->huile == -1)
		return ("famine");
		
}

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