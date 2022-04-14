/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:36:33 by estarck           #+#    #+#             */
/*   Updated: 2022/04/14 15:14:05 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cpy_to_lst(char *str, int j)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != 32)
	{
		tmp[i] = str[i];
		i++;
	}
	return (i);
}

void	cpy_int(t_ab *ab, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] >= 48 && argv[i][j] <= 57)
				j = j + cpy_to_lst(argv[i]);
			j++;
		}
		i++;
	}
}