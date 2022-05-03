/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:48:10 by estarck           #+#    #+#             */
/*   Updated: 2022/05/03 22:31:56 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_btoa_n(t_ab *ab, t_data *elem)
{
	while (elem->rra)
	{
		if (elem->rrb > 0)
		{
			instructions(ab, rrr);
			(elem->rrb)--;
		}
		else
			instructions(ab, rra);
		(elem->rra)--;
	}
	while (elem->rrb)
	{
		instructions(ab, rrb);
		(elem->rrb)--;
	}
	instructions(ab, pa);
	(ab->si_st_a)++;
	(ab->si_st_b)--;
}

static void	push_btoa(t_ab *ab, t_data *elem)
{
	while (elem->ra)
	{
		if (elem->rb > 0)
		{
			instructions(ab, rr);
			(elem->rb)--;
		}
		else
			instructions(ab, ra);
		(elem->ra)--;
	}
	while (elem->rb)
	{
		instructions(ab, rb);
		(elem->rb)--;
	}
	push_btoa_n(ab, elem);
}

static void	check_score(t_ab *ab)
{
	t_data	*tmp;

	tmp = (*ab->b);
	while (tmp != NULL)
	{
		if (tmp->nbr > ab->med_elem && ab->c_med <= (ab->mid_size)
			&& ab->c_supmed_b <= (ab->mid_size / 3))
		{
			instructions(ab, rb);
			(ab->c_med)++;
			break ;
		}
		if (ab->bst_elem == tmp->score)
		{
			push_btoa(ab, tmp);
			break ;
		}
		tmp = tmp->next;
	}
}

static void	push_atob(t_ab *ab)
{
	int	i;

	i = 0;
	while (ab->size_tt - i > 3)
	{
		if ((ab->min_elem == (*ab->a)->nbr) || (ab->max_elem == (*ab->a)->nbr)
			|| (ab->med_elem == (*ab->a)->nbr))
		{
			instructions(ab, ra);
			continue ;
		}
		instructions(ab, pb);
		if (i > ab->mid_size && ab->med_elem < (*ab->b)->nbr)
			(ab->c_supmed_b)++;
		i++;
	}
	ab->si_st_a = 3;
	ab->si_st_b = i;
	sort_three(ab, ab->a);
}

void	start_algo(t_ab *ab)
{
	if (ab->size_tt == 2)
		sort_two(ab);
	if (ab->size_tt == 3)
		sort_three(ab, ab->a);
	if (ab->size_tt == 5)
		sort_five(ab);
	if (ab->size_tt > 5)
	{
		push_atob(ab);
		while (ab->si_st_b)
		{
			score_elem_b(ab);
			check_score(ab);
		}
		close_algo(ab);
	}
}
