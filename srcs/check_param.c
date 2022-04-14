/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:12:40 by estarck           #+#    #+#             */
/*   Updated: 2022/04/14 12:31:54 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	are_int(t_ab *ab, char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv [i] < 32 || (argv[i] > 32 && argv[i] < 48) || argv[i] > 57)
			ft_perror(ab, "Error", 2);
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
	ft_printf("Params ok\n");
}
