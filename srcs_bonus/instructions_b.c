/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:22:23 by estarck           #+#    #+#             */
/*   Updated: 2022/05/05 20:03:16 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mp_reverse(t_ab *ab, t_op op)
{
	if (op == rra && ab->si_st_a > 1)
		rev_element(ab->a);
	if (op == rrb && ab->si_st_b > 1)
		rev_element(ab->b);
	if (op == rrr)
	{
		if (ab->si_st_a > 1)
			rev_element(ab->a);
		if (ab->si_st_b > 1)
			rev_element(ab->b);
	}
}

static void	mp_rotate(t_ab *ab, t_op op)
{
	if (op == ra && ab->si_st_a > 1)
		rot_element(ab->a);
	if (op == rb && ab->si_st_b > 1)
		rot_element(ab->b);
	if (op == rr)
	{
		if (ab->si_st_a > 1)
			rot_element(ab->a);
		if (ab->si_st_b > 1)
			rot_element(ab->b);
	}
}

static void	mp_push(t_ab *ab, t_op op)
{
	if (op == pa && ab->si_st_b > 0)
		push_element(ab, op);
	if (op == pb && ab->si_st_a > 0)
		push_element(ab, op);
}

static void	mp_swap(t_ab *ab, t_op op)
{
	if (op == sa)
		swap_elements(*ab->a);
	if (op == sb)
		swap_elements(*ab->b);
	if (op == ss)
	{
		if (ab->si_st_a > 1)
			swap_elements(*ab->a);
		if (ab->si_st_b > 1)
			swap_elements(*ab->b);
	}
}

void	instructions(t_ab *ab, t_op op)
{
	if (op >= sa && op <= ss)
		mp_swap(ab, op);
	if (op == pa || op == pb)
		mp_push(ab, op);
	if (op >= ra && op <= rr)
		mp_rotate(ab, op);
	if (op >= rra && op <= rrr)
		mp_reverse(ab, op);
}
