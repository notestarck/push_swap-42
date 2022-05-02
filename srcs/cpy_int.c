/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:36:33 by estarck           #+#    #+#             */
/*   Updated: 2022/05/02 14:43:35 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void count_elements(t_ab *ab)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = (*ab->a);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	ab->size = i;
	ft_printf("Nombre d'elements : %d\n\n", ab->size); //a supprimer
}

static void	int_is_dup(t_ab *ab, int nbr)
{
	t_data	*tmp;

	tmp = (*ab->a);
	while (tmp->next != NULL)
	{
		if (tmp->nbr == nbr)
			ft_perror(ab, "Error", 3);
		tmp = tmp->next;
	}
}

static int	cpy_to_lst(char *str, t_data *a_lst, t_ab *ab)
{
	int					i;
	int					s;
	unsigned long int	r;

	i = 0;
	r = 0;
	s = 1;
	if (str[i] == '-')
	{
		s = -s;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	if (r > 2147483648 && s < 0)
		ft_perror(ab, "Error", 3);
	if (r > 2147483647 && s > 0)
		ft_perror(ab, "Error", 3);
	a_lst->nbr = r * s;
	return (i);
}

static t_data	*create_lst(t_ab *ab)
{
	t_data	*a_lst;
	t_data	*tmp;

	tmp = (*ab->a);
	a_lst = malloc(sizeof(t_data));
	if (a_lst == 0x0)
		ft_perror(ab, "Error - Malloc create_lst", 3); //gerer le free de chaine
	if (*ab->a == NULL)
	{
		(*ab->a) = a_lst;
		return (a_lst);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = a_lst;
	return (a_lst);
}

void	cpy_int(t_ab *ab, char **argv)
{
	int		c;
	t_data	*a_lst;

	c = 0;
	argv++;
	while (*argv)
	{
		while (**argv)
		{
			if ((**argv >= 48 && **argv <= 57) || **argv == 45)
			{
				a_lst = create_lst(ab);
				c = cpy_to_lst(*argv, a_lst, ab);
				int_is_dup(ab, a_lst->nbr);
				*argv = *argv + c;
			}
			else
				(*argv)++;
		}
		argv++;
	}	
	count_elements(ab);
}
