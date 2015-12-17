/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:48:08 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/12 18:42:13 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fee_1337.h"

static void	print_usage(int ac)
{
	if (ac != 2)
		ft_putendl("\033[32m\tusage: ./fillit [File]\n\033[0m");
	else
		ft_putstr("\033[35m\n\t *****Welcome to Fee 1337*****\n\n\033[0m");
}

int		main(int ac, char **av)
{
	print_usage(ac);
	if (ac == 2)
		fee_1337(av[1]);
	return (0);
}