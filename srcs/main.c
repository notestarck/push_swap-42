/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:41:34 by estarck           #+#    #+#             */
/*   Updated: 2022/05/01 22:50:17 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void test(t_ab *ab) //a Supprimer
{
	t_data	*tmp;
	t_data	*tmp2;

	tmp = ab->a;
	tmp2 = ab->b;
	ft_printf("\n");
	while (tmp != NULL)
	{
		ft_printf("pile a : %d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("\n");
	while (tmp2 != NULL)
	{
		ft_printf("pile b : %d\n", tmp2->nbr);
		tmp2 = tmp2->next;
	}
}

static t_ab	*init_ps(int argc)
{
	t_ab	*ab;

	if (argc == 1)
		exit (0);
	ab = malloc(sizeof(t_ab));
	if (ab == NULL)
		ft_perror(ab, "Error Malloc - t_ab *ab - init_ps", 1);
	return (ab);
}

int	main(int argc, char **argv)
{
	t_ab	*ab;

	ab = init_ps(argc);
	check_param(ab, argc, argv);
	cpy_int(ab, argv);
	
	instructions(ab, ra);
	test(ab);
	return (0);
}
