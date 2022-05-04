/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:20:02 by estarck           #+#    #+#             */
/*   Updated: 2022/05/04 11:28:25 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		i++;
	}
}

static void	find_element(t_ab *ab)
{
	int		tab[10001];
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = (*ab->a);
	while (tmp != NULL)
	{
		tab[i] = tmp->nbr;
		i++;
		tmp = tmp->next;
	}
	ft_sort_int_tab(tab, i);
	ab->mid_size = i / 2;
	ab->med_elem = tab[ab->mid_size];
}

void	init_elements(t_ab *ab)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = (*ab->a);
	ab->min_elem = tmp->nbr;
	ab->med_elem = tmp->nbr;
	ab->max_elem = tmp->nbr;
	while (tmp != NULL)
	{
		if (tmp->nbr > ab->max_elem)
			ab->max_elem = tmp->nbr;
		if (tmp->nbr < ab->min_elem)
			ab->min_elem = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	ab->size_tt = i;
	find_element(ab);
}
