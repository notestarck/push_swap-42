/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:24:36 by estarck           #+#    #+#             */
/*   Updated: 2022/05/01 22:50:35 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_elements(t_data *first)
{
	int		tmp;
	t_data	*second;

	tmp = first->nbr;
	second = first->next;
	if (first->next != NULL)
	{
		first->nbr = second->nbr;
		second->nbr = tmp;
	}
	return (0);
}

int	push_element(t_ab *ab, t_op op)
{
	t_data	*tmp;

	if (op == pa && ab->b != NULL)
	{
		tmp = ab->a;
		ab->a = ab->b;
		ab->b = ab->b->next;
		ab->a->next = tmp;
	}
	else if (op == pb && ab->a != NULL)
	{
		tmp = ab->b;
		ab->b = ab->a;
		ab->a = ab->a->next;
		ab->b->next = tmp;
	}
	return (0);
}

int	rot_element(t_ab *ab, t_op op)
{
	t_data	*tmp;

	if (op == ra)
	{
		tmp = ab->a;
		ab->a = ab->a->next;
		while (ab->a->next != NULL)
			ab->a = ab->a->next;
		ab->a->next = tmp;
		ab->a = ab->a->next;
		ab->a->next = NULL;
	}
	return (0);
}
