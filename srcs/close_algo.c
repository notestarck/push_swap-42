/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:28:55 by estarck           #+#    #+#             */
/*   Updated: 2022/05/06 07:16:52 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	close_algo_n(t_ab *ab, int i)
{
	if (i <= (ab->mid_size) && i > 0)
	{
		while (i)
		{
			instructions(ab, ra);
			i--;
		}
	}
	else if (i > (ab->mid_size) && i > 0)
	{
		i = ab->size_tt - i;
		while (i)
		{
			instructions(ab, rra);
			i--;
		}
	}
}

void	close_algo(t_ab *ab)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = (*ab->a);
	while (tmp != NULL)
	{
		if (tmp->nbr == ab->min_elem)
			break ;
		i++;
		tmp = tmp->next;
	}
	close_algo_n(ab, i);
}
