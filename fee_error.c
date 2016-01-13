/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/12 19:50:48 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

static void		error_char(t_data *d, char **t)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (!is_tetrichar(t[j][i]))
				exit(tt_ps(ERR, 0));
			if (t[j][i] == '#' && ++k > 4)
				exit(tt_ps(ERR, 0));
			++i;
		}
		++j;
	}
	if (k < 4)
		exit(tt_ps(ERR, 0));
	d->nb_blocks++;
}

static int	error_block(t_data *d, int fd)
{
	char	*line;
	int		i;
	int		eof;

	i = 0;
	line = ft_strnew(5);
	d->t = tt_malloc_tab(5, 5);
	while ((eof = get_next_line(fd, &line)) >= 0)
	{
		ft_strcpy(d->t[i], line);
		if (ft_strlen(line) != 4 && i != 4)
			exit(tt_ps(ERR, 0));
		else if (i == 4)
		{
			if ((ft_strcmp(line, "") && eof) || (!ft_strcmp(line, "") && !eof))
				exit(tt_ps(ERR, 0));
			error_char(d, d->t);
			if (!eof)
				break ;
			i = -1;
		}
		i++;
	}
	tt_del_tab(d->t, 5);
	return (1);
}

int		fee_error(t_data *d)
{
	int		fd;
	
	if (!(fd = open(d->file, O_RDONLY)))
    	exit(tt_ps(ERR, 0));
    error_block(d, fd);
    close(fd);
    return (1);
}