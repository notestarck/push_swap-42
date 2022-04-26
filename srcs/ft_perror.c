/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:19:28 by estarck           #+#    #+#             */
/*   Updated: 2022/04/26 11:27:08 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_perror(t_ab *ab, char *str, int lvl_free)
{
	ft_printf("\x1b[31m%s\e[0m\n",str);
	if (lvl_free == 3)
	{
		//Faire une free de chaine
		lvl_free--;
	}
	if (lvl_free == 2)
	{
		free(ab);
		lvl_free--;
	}
	if (lvl_free == 1)
		exit (0);
}
