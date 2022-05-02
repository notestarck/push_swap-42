/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:48:10 by estarck           #+#    #+#             */
/*   Updated: 2022/05/02 23:11:27 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_btoa(t_ab *ab, t_data *elem)
{
	while (elem->ra)
	{
		instructions(ab, ra);
		(elem->ra)--;
	}
	while (elem->rb)
	{
		instructions(ab, rb);
		(elem->rb)--;
	}
	while (elem->rra)
	{
		instructions(ab, rra);
		(elem->rra)--;
	}
	while (elem->rrb)
	{
		instructions(ab, rrb);
		(elem->rrb)--;
	}
	instructions(ab, pa);
	(ab->stack_a)++;
	(ab->stack_b)--;
}

static void	push_atob(t_ab *ab)
{
	int	i;

	i = 0;
	while (ab->size - i > 3)
	{
		instructions(ab, pb);
		i++;
	}
	ab->stack_a = 3;
	ab->stack_b = i;
	sort_three(ab, ab->a);
	t_data	*tmp;
	while (ab->stack_b != 0)
	{
		score_elem_b(ab);
		tmp = (*ab->b);
		while (tmp != NULL)
		{
			if (ab->bst_elem == tmp->score)
			{
				push_btoa(ab, tmp);
				break ;
			}
			tmp = tmp->next;
		}
	}
}

void	start_algo(t_ab *ab)
{
	if (ab->size == 2)
		sort_two(ab);
	if (ab->size == 3)
		sort_three(ab, ab->a);
	if (ab->size >= 4)
		push_atob(ab);
}