/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sandglass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:03:58 by junyoo            #+#    #+#             */
/*   Updated: 2023/01/04 12:34:58 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static size_t	dq_get_first_index(t_deque *deque)
{
	return (deque->first->index);
}

static void	a_to_b(t_deque *a, t_deque *b, int chunk, size_t i)
{
	size_t	first_index;

	while (a->size != 0)
	{
		first_index = dq_get_first_index(a);
		if (first_index <= i)
		{
			push(a, b, PB);
			i++;
		}
		else if (first_index > i && first_index <= i + chunk)
		{
			push(a, b, PB);
			rotate(a, b, RB);
			i++;
		}
		else if (first_index > (i + chunk))
		{
			if (i < a->size / 2 && i >= 0)
				reverse_rotate(a, b, RRA);
			else
				rotate(a, b, RA);
		}
	}
}

static void	sort_b(t_deque *a, t_deque *b, size_t length)
{
	size_t	i;
	t_node	*node;

	node = b->last;
	i = 0;
	while (i < b->size && node->index != length)
	{
		node = node->prev;
		i++;
	}
	while (i < b->size / 2 && i >= 0)
	{
		reverse_rotate(a, b, RRB);
		i--;
	}
	while (i >= b->size / 2 && i < b->size - 1)
	{
		rotate(a, b, RB);
		i++;
	}
}

static void	b_to_a(t_deque *a, t_deque *b)
{
	int	length;

	length = b->size - 1;
	while (b->size != 0)
	{
		sort_b(a, b, length);
		push(a, b, PA);
		length--;
	}
}

void	sort_sandglass(t_deque *a, t_deque *b)
{
	int	x;
	int	chunk;

	x = a->size;
	chunk = 0.03 * x + 12.5;
	a_to_b(a, b, chunk, 0);
	b_to_a(a, b);
}
