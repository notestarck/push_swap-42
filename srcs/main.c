/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:41:34 by estarck           #+#    #+#             */
/*   Updated: 2022/05/03 22:14:06 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ab	*init_ps(int argc)
{
	t_ab	*ab;

	if (argc == 1)
		exit (0);
	ab = malloc(sizeof(t_ab));
	if (ab == NULL)
		ft_perror(ab, "Error Malloc - t_ab *ab - init_ps\n", 1);
	ab->a = malloc(sizeof(t_data));
	if (ab->a == NULL)
		ft_perror(ab, "Error Mallox - ab->a - init_ps\n", 2);
	ab->b = malloc(sizeof(t_data));
	if (ab->b == NULL)
		ft_perror(ab, "Error Mallox - ab->b - init_ps\n", 3);
	return (ab);
}

int	main(int argc, char **argv)
{
	t_ab	*ab;

	ab = init_ps(argc);
	check_param(ab, argc, argv);
	cpy_int(ab, argv);
	start_algo(ab);
	return (0);
}
