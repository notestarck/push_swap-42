/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:52:40 by estarck           #+#    #+#             */
/*   Updated: 2022/05/06 07:13:49 by estarck          ###   ########.fr       */
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
		ft_perror(ab, "Error Malloc - ab->a - init_ps\n", 2);
	ab->b = malloc(sizeof(t_data));
	if (ab->b == NULL)
		ft_perror(ab, "Error Malloc - ab->b - init_ps\n", 3);
	return (ab);
}

int	main(int argc, char **argv)
{
	t_ab	*ab;

	if (argc == 1)
		exit (0);
	ab = init_ps(argc);
	check_param(ab, argc, argv);
	cpy_int(ab, argv);
	if (ab->size_tt == 1)
		ft_perror(NULL, "Error\n", 0);
	read_stdin(ab);
	ft_perror(ab, NULL, 4);
	return (0);
}
