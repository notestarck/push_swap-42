/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:10:37 by estarck           #+#    #+#             */
/*   Updated: 2022/05/02 15:34:51 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_ab *ab)
{
	if ((*ab->a)->nbr > (*ab->a)->next->nbr)
		instructions(ab, sa);
}

void	sort_three(t_ab *ab, t_data **s)
{
	if (((*s)->nbr > (*s)->next->nbr)
		&& ((*s)->next->nbr > (*s)->next->next->nbr))
	{
		instructions(ab, ra);
		instructions(ab, sa);
	}
	else if ((*s)->nbr > (*s)->next->nbr
		&& ((*s)->next->nbr < (*s)->next->next->nbr)
		&& ((*s)->nbr < (*s)->next->next->nbr))
		instructions(ab, sa);
	else if ((*s)->nbr > (*s)->next->nbr
		&& ((*s)->next->nbr < (*s)->next->next->nbr)
		&& ((*s)->nbr > (*s)->next->next->nbr))
		instructions(ab, ra);
	else if ((*s)->nbr < (*s)->next->nbr
		&& ((*s)->next->nbr > (*s)->next->next->nbr))
	{
		instructions(ab, rra);
		if ((*s)->nbr > (*s)->next->nbr)
			instructions(ab, sa);
	}
}