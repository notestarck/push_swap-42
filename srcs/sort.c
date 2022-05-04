/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:10:37 by estarck           #+#    #+#             */
/*   Updated: 2022/05/04 15:46:48 by estarck          ###   ########.fr       */
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

void	sort_four(t_ab *ab)
{
	instructions(ab, pb);
	ab->si_st_a = 3;
	ab->si_st_b = 1;
	sort_three(ab, ab->a);
	while (ab->si_st_b)
	{
		score_elem_b(ab);
		check_score(ab);
	}
	close_algo(ab);
}

void	sort_five(t_ab *ab)
{
	instructions(ab, pb);
	instructions(ab, pb);
	ab->si_st_a = 3;
	ab->si_st_b = 2;
	sort_three(ab, ab->a);
	while (ab->si_st_b)
	{
		score_elem_b(ab);
		check_score(ab);
	}
	close_algo(ab);
}
