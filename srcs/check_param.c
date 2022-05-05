/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:12:40 by estarck           #+#    #+#             */
/*   Updated: 2022/05/05 09:10:39 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	are_int(t_ab *ab, char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != 32 && argv[i] != 45 && (argv[i] < 48 || argv[i] > 57))
			ft_perror(ab, "Error\n", 3);
		i++;
	}
}

void	check_param(t_ab *ab, int argc, char **argv)
{
	while (argc > 1)
	{
		are_int(ab, argv[argc - 1]);
		argc--;
	}
}
