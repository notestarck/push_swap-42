/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:42:42 by estarck           #+#    #+#             */
/*   Updated: 2022/04/14 12:16:55 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef enum e_bool
{
	false,
	true
} t_bool;

typedef struct s_ab
{
	char	*a;
	char	*b;
}	t_ab;


//Gestion des erreurs
void	ft_perror(t_ab *ab, char *str, int lvl_free);

//Check parametres
void	check_param(t_ab *ab, int argc, char **argv);

#endif