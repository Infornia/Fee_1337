/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_blocks_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/12 19:50:48 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

static int	blocks_read(t_data *d, int fd)
{
	char	*line;
	int		i;
	int		block_nb;
	int		eof;

	i = 0;
	block_nb = 0;
	line = ft_strnew(5);
	d->t = tt_malloc_tab(5, 5);
	while ((eof = get_next_line(fd, &line)) >= 0)
	{
		ft_strcpy(d->t[i], line);
		if (i == 4)
		{
			if (!eof)
				break ;
			i = -1;
			d->blocks[block_nb++] = d->t;
			d->t = tt_malloc_tab(5, 5);
		}
		i++;
	}
	return (1);
}


void    fee_blocks_get(t_data *d)
{
	int		fd;
	
	if (d->nb_blocks > 26)
    	exit (tt_ps("Too Many blocks", 0));
    if (!(d->blocks = (char ***)malloc(sizeof(char**) * d->nb_blocks)))
    	exit (tt_ps("Malloc Failed", 0));
	if (!(fd = open(d->file, O_RDONLY)))
    	exit (tt_puterr("Open file", d->file, 0));
    if (!(blocks_read(d, fd)))
        exit (tt_ps("Failed to create Blocks", 0));
    close(fd);
    return ((void)tt_ps("Blocks Created", 1));
}