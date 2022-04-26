/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:22:23 by estarck           #+#    #+#             */
/*   Updated: 2022/04/26 18:23:37 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mp_rotate(t_ab *ab, t_op op)
{
	if (op == ra)
	{
		rot_element(ab, op);
		ft_printf("ra\n");
	}
	if (op == rb)
	{
		rot_element(ab, op);
		ft_printf("rb\n");
	}
}

static void	mp_push(t_ab *ab, t_op op)
{
	if (op == pa)
	{
		push_element(ab, op);
		ft_printf("pa\n");
	}
	if (op == pb)
	{
		push_element(ab, op);
		ft_printf("pb\n");
	}
}

static void	mp_swap(t_ab *ab, t_op op)
{
	if (op == sa)
	{
		swap_elements(ab->a);
		ft_printf("sa\n");
	}
	if (op == sb)
	{
		swap_elements(ab->b);
		ft_printf("sb\n");
	}
	if (op == ss)
	{
		swap_elements(ab->a);
		swap_elements(ab->b);
		ft_printf("ss\n");
	}
}

void	instructions(t_ab *ab, t_op op)
{
	if (op >= sa && op <= ss)
		mp_swap(ab, op);
	if (op == pa || op == pb)
		mp_push(ab, op);
	if (op == ra || op == rb)
		mp_rotate(ab, op);	
}
