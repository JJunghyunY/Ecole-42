/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:28:46 by junyoo            #+#    #+#             */
/*   Updated: 2023/01/04 23:00:12 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_3_arg(t_deque *a, t_deque *b)
{
	t_node	*curr;

	curr = a->first->next;
	if (a->first->index == 0)
	{
		swap(a, b, SA);
		rotate(a, b, RA);
	}
	else if (a->first->index == 1)
	{
		if (curr->index == 0)
			swap(a, b, SA);
		else
			reverse_rotate(a, b, RRA);
	}
	else if (a->first->index == 2)
	{
		if (curr->index == 0)
			rotate(a, b, RA);
		else
		{
			rotate(a, b, RA);
			rotate(a, b, RA);
		}
	}
}

void	sort_4_arg(t_deque *a, t_deque *b)
{
	int		min;
	t_node	*curr;

	min = a->first->value;
	curr = a->first;
	while (curr)
	{
		if (min > curr->value)
			min = curr->value;
		curr = curr->next;
	}
	while (a->first->value != min)
		rotate(a, b, RA);
	if (is_sorted(a) != 1)
	{
		push(a, b, PB);
		sort_3_arg(a, b);
		push(a, b, PA);
	}
}

void	sort_5_arg(t_deque *a, t_deque *b)
{
	while (a->first->index != 0 || a->first->index != 1)
		rotate(a, b, RA);
	push(a, b, PB);
	while (a->first->index != 1 || a->first->index != 0)
		rotate(a, b, RA);
	push(a, b, PB);
	if (is_sorted(a) != 1)
		sort_3_arg(a, b);
	if (b->first->value < b->last->value)
		swap(a, b, SB);
	push(a, b, PA);
	push(a, b, PA);
}
