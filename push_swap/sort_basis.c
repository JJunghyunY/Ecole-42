/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:28:46 by junyoo            #+#    #+#             */
/*   Updated: 2023/01/08 22:24:49 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static size_t	dq_get_min(t_deque *deque)
{
	size_t	min;
	t_node	*curr;

	min = deque->first->index;
	curr = deque->first;
	while (curr)
	{
		if (min > curr->index)
			min = curr->index;
		curr = curr->next;
	}
	return (min);
}

void	sort_3_arg(t_deque *a, t_deque *b)
{
	t_node	*next;

	next = a->first->next;
	if (a->first->index > next->index)
	{
		next = next->next;
		if (a->first->index > next->index)
			rotate(a, b, RA);
		next = a->first->next;
		if (a->first->index > next->index)
			swap(a, b, SA);
	}
	else
	{
		if (a->first->index > next->index)
			swap(a, b, SA);
		else
			reverse_rotate(a, b, RRA);
		next = a->first->next;
		if (a->first->index > next->index)
			swap(a, b, SA);
	}
}

void	sort_4_arg(t_deque *a, t_deque *b)
{
	size_t	min;

	min = dq_get_min(a);
	while (a->first->index != min)
		rotate(a, b, RA);
	push(a, b, PB);
	if (is_sorted(a) != 1)
		sort_3_arg(a, b);
	push(a, b, PA);
}

# include <stdio.h>

void	sort_5_arg(t_deque *a, t_deque *b)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (a->first->index <= 1)
			push(a, b, PB);
		else
			rotate(a, b, RA);
		i++;
	}
	if (is_sorted(a) != 1)
		sort_3_arg(a, b);
	if (b->first->index < b->last->index)
		swap(a, b, SB);
	push(a, b, PA);
	push(a, b, PA);
}
