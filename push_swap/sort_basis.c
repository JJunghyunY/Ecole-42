/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:28:46 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/30 20:07:19 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_3_arg(t_deque *a, t_deque *b)
{
	t_node	*curr;

	curr = a->first->next;
	if (a->first->value > curr->value)
	{
		curr = curr->next;
		if (a->first->value > curr->value)
			rotate(a, b, RA);
		curr = a->first->next;
		if (a->first->value > curr->value)
			swap(a, b, SA);
	}
	else
	{
		if (curr->value < curr->next->value)
			swap(a, b, SA);
		else if (curr->value > curr->next->value)
		{
			reverse_rotate(a, b, RRA);
			if (a->first->value > a->first->next->value)
				swap(a, b, SA);
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
	int		countpb;

	countpb = 0;
	while (countpb != 2)
	{
		if (a->first->index < 2)
		{
			push(a, b, PB);
			countpb++;
		}
		else
			rotate(a, b, RA);
	}
	if (is_sorted(a) != 1)
		sort_3_arg(a, b);
	if (b->first->value < b->last->value)
		swap(a, b, SB);
	push(a, b, PA);
	push(a, b, PA);
}
