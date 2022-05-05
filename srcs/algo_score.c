/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:52:15 by estarck           #+#    #+#             */
/*   Updated: 2022/05/05 14:19:44 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_score(t_data *tmp)
{
	tmp->score = 0;
	if (tmp->ra <= tmp->rra)
	{
		tmp->score = tmp->ra + tmp->score;
		tmp->rra = 0;
	}
	else
	{
		tmp->score = tmp->rra + tmp->score;
		tmp->ra = 0;
	}
	if (tmp->rb <= tmp->rrb)
	{
		tmp->score = tmp->rb + tmp->score;
		tmp->rrb = 0;
	}
	else
	{
		tmp->score = tmp->rrb + tmp->score;
		tmp->rb = 0;
	}
}

static int	score_compare_a(t_ab *ab, t_data *b)
{
	int		i;
	t_data	*tmp;

	i = 1;
	tmp = (*ab->a);
	while (tmp != 0)
	{
		if (tmp->next != NULL && ((b->nbr > tmp->nbr && b->nbr < tmp->next->nbr)
				|| ((tmp->nbr == ab->max_elem) && b->nbr == ab->min_elem)
				|| ((b->nbr == ab->max_elem)
					&& tmp->next->nbr == ab->min_elem)))
		{
			b->ra = i;
			b->rra = ab->si_st_a - i;
			return (0);
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	score_elem_b(t_ab *ab)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = (*ab->b);
	ab->bst_elem_score = ab->size_tt;
	while (tmp != NULL)
	{
		tmp->rb = i;
		if (i != 0)
			tmp->rrb = ab->si_st_b - i;
		score_compare_a(ab, tmp);
		final_score(tmp);
		if (tmp->score < (ab->bst_elem_score))
		{
			ab->bst_elem_score = tmp->score;
			ab->bst_elem = tmp->nbr;
		}
		tmp = tmp->next;
		i++;
	}
}
