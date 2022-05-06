/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:05:31 by estarck           #+#    #+#             */
/*   Updated: 2022/05/06 07:34:07 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_sort(t_ab *ab)
{
	t_data	*tmp;

	tmp = (*ab->a);
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->nbr > tmp->next->nbr)
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL && (*ab->b) == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static void	push_instruction_n(t_ab *ab, char *str)
{
	if (*str == 'r' && *(str + 2) == '\n' && (*(str + 1) == 'a'
			|| *(str + 1) == 'b' || *(str + 1) == 'r'))
	{
		str++;
		if (*str == 'a')
			instructions(ab, ra);
		if (*str == 'b')
			instructions(ab, rb);
		if (*str == 'r')
			instructions(ab, rr);
	}
	else if (*str == 'r' && *(str + 3) == '\n' && *(str + 1) == 'r'
		&& (*(str + 2) == 'a' || *(str + 2) == 'b' || *(str + 2) == 'r'))
	{
		str += 2;
		if (*str == 'a')
			instructions(ab, rra);
		if (*str == 'b')
			instructions(ab, rrb);
		if (*str == 'r')
			instructions(ab, rrr);
	}
	else
		ft_perror(ab, "Error\n", 42);
}

static void	push_instruction(t_ab *ab, char *str)
{
	if (*str == 's' && *(str + 2) == '\n' && (*(str + 1) == 'a'
			|| *(str + 1) == 'b' || *(str + 1) == 's'))
	{
		str++;
		if (*str == 'a')
			instructions(ab, sa);
		if (*str == 'b')
			instructions(ab, sb);
		if (*str == 's')
			instructions(ab, ss);
	}
	else if (*str == 'p' && *(str + 2) == '\n'
		&& (*(str + 1) == 'a' || *(str + 1) == 'b'))
	{
		str++;
		if (*str == 'a')
			instructions(ab, pa);
		if (*str == 'b')
			instructions(ab, pb);
	}
	else
		push_instruction_n(ab, str);
}

void	read_stdin(t_ab *ab)
{
	char	*buf;
	char	*tmp;
	char	*dst;

	buf = malloc(sizeof(char));
	while (read(1, buf, 42))
	{
		tmp = malloc(sizeof(char));
		dst = malloc(sizeof(char));
		dst = ft_strjoin(tmp, buf);
		push_instruction(ab, dst);
		free(dst);
		free (tmp);
	}
	check_sort(ab);
	free(buf);
}
