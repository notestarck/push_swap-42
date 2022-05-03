/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:42:42 by estarck           #+#    #+#             */
/*   Updated: 2022/05/03 22:31:42 by estarck          ###   ########.fr       */
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
}	t_bool;

typedef enum e_operations
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_op;

typedef struct s_data	t_data;

struct s_data
{
	int		nbr;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		score;
	t_data	*next;
};

typedef struct s_ab
{
	t_data	**a;
	t_data	**b;
	int		size_tt;
	int		si_st_a;
	int		si_st_b;
	int		c_med;
	int		c_supmed_b;
	int		mid_size;
	int		min_elem;
	int		med_elem;
	int		max_elem;
	int		bst_elem;
}	t_ab;

//Gestion des erreurs
void	ft_perror(t_ab *ab, char *str, int lvl_free);

//Check et copies parametres
void	check_param(t_ab *ab, int argc, char **argv);
void	cpy_int(t_ab *ab, char **argv);

//Operations et instructions
int		swap_elements(t_data *first);
int		push_element(t_ab *ab, t_op op);
int		rot_element(t_data **first);
int		rev_element(t_data **first);
void	instructions(t_ab *ab, t_op op);

//Mise en place lst
void	init_elements(t_ab *ab);

//Algorithme
void	start_algo(t_ab *ab);
void	score_elem_b(t_ab *ab);
void	sort_two(t_ab *ab);
void	sort_five(t_ab *ab);
void	sort_three(t_ab *ab, t_data **s);
void	close_algo(t_ab *ab);

#endif