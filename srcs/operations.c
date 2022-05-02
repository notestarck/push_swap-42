/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:24:36 by estarck           #+#    #+#             */
/*   Updated: 2022/05/02 12:32:49 by estarck          ###   ########.fr       */
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

	if (op == pa && *ab->b != NULL)
	{
		tmp = *ab->a;
		*ab->a = *ab->b;
		*ab->b = (*ab->b)->next;
		(*ab->a)->next = tmp;
	}
	else if (op == pb && *ab->a != NULL)
	{
		tmp = *ab->b;
		*ab->b = *ab->a;
		*ab->a = (*ab->a)->next;
		(*ab->b)->next = tmp;
	}
	return (0);
}

int	rot_element(t_data **first)
{
	t_data	*tmp;

	tmp = *first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *first;
	*first = (*first)->next;
	tmp = tmp->next;
	tmp->next = NULL;
	return (0);
}

int	rev_element(t_data **first)
{
	t_data	*tmp;

	tmp = *first;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *first;
	*first = tmp->next;
	tmp->next = NULL;
	return (0);
}
