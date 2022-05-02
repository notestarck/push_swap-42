/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:52:15 by estarck           #+#    #+#             */
/*   Updated: 2022/05/02 23:23:19 by estarck          ###   ########.fr       */
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

static int	last_nbr(t_data *a)
{
	int		nbr;
	t_data	*tmp;

	nbr = 0;
	tmp = a;
	while (tmp != NULL)
	{
		nbr = tmp->nbr;
		tmp = tmp->next;
	}
	return (nbr);
}

static int	score_compare_a(t_ab *ab, t_data *b)
{
	int		i;
	int		nbr_a;
	t_data	*tmp_a;

	i = 0;
	nbr_a = last_nbr((*ab->a));
	tmp_a = (*ab->a);
	while (tmp_a != NULL)
	{
		b->ra = i;
		b->rra = ab->stack_a - i;
		if (i == 0 && ((b->nbr < tmp_a->nbr && b->nbr < nbr_a && tmp_a->nbr < nbr_a) || (b->nbr > tmp_a->nbr && b->nbr > nbr_a)))
			return (0);
		if (tmp_a->next != NULL && (b->nbr > tmp_a->nbr
				&& b->nbr < tmp_a->next->nbr))
		{
			(b->ra)++;
			b->rra = ab->stack_a - b->ra;
			return (0);
		}
		i++;
		tmp_a = tmp_a->next;
	}
	return (0);
}

void	score_elem_b(t_ab *ab)
{
	int		i;
	t_data	*tmp_b;

	i = 0;
	tmp_b = (*ab->b);
	while (tmp_b != NULL)
	{
		tmp_b->rb = i;
		tmp_b->rrb = ab->stack_b - i;
		score_compare_a(ab, tmp_b);
		//ft_printf("pile b : %d \t score : %d, ra : %d, rb : %d, rra : %d, rrb : %d\n", tmp_b->nbr, tmp_b->score, tmp_b->ra, tmp_b->rb, tmp_b->rra, tmp_b->rrb);
		i++;
		tmp_b = tmp_b->next;
	}
	tmp_b = (*ab->b);
	ab->bst_elem = 10;
	while (tmp_b != NULL)
	{
		final_score(tmp_b);
		if (tmp_b->score <= ab->bst_elem)
			ab->bst_elem = tmp_b->score;
		ft_printf("la pile b : %d \t score : %d, ra : %d, rb : %d, rra : %d, rrb : %d\n", tmp_b->nbr, tmp_b->score, tmp_b->ra, tmp_b->rb, tmp_b->rra, tmp_b->rrb);
		tmp_b = tmp_b->next;
	}
}