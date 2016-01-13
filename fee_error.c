/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fee_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:53:17 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/13 21:08:42 by mwilk            ###   ########.fr       */
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
			if (i == 3 && t[j][i] == '\n')
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
	while ((eof = read(fd, line, 5)) > 0)
	{
		if (i < 4)
		{
			ft_strncpy(d->t[i], line, 4);
			if (eof == 4)
				exit(tt_ps(ERR, 0));
			if (i == 3 && (eof = read(fd, line, 1)) == 1 && !ft_strncmp(line, "\n", 1))
			{
				error_char(d, d->t);
				i = -1;
			}
		}
		else
			exit(tt_ps(ERR, 0));
		i++;
	}
	tt_deltab(d->t, 5);
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
