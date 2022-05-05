/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:19:28 by estarck           #+#    #+#             */
/*   Updated: 2022/05/05 08:21:00 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_str(t_data *str)
{
	t_data	*tmp;

	while (str != NULL)
	{
		tmp = str->next;
		free(str);
		str = tmp;
	}
}

void	ft_perror(t_ab *ab, char *str, int lvl_free)
{
	if (str != NULL)
		ft_putstr_fd(str, 2);
	if (lvl_free == 4)
	{
		free_str(*ab->a);
		lvl_free--;
	}
	if (lvl_free == 3)
	{
		free(ab->b);
		lvl_free--;
	}
	if (lvl_free == 2)
	{
		free(ab->a);
		lvl_free--;
	}
	if (lvl_free == 1)
		free(ab);
	exit (0);
}
