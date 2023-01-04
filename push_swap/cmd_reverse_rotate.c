/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:59:09 by junyoo            #+#    #+#             */
/*   Updated: 2023/01/04 21:27:06 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	_reverse_rotate(t_deque *deque)
{
	int		value;
	size_t	index;

	if (deque->first == NULL)
		return (0);
	value = deque->last->value;
	index = deque->last->index;
	dq_pop_back(deque);
	dq_push_front(deque, value);
	deque->first->index = index;
	return (1);
}

void	reverse_rotate(t_deque *a, t_deque *b, t_cmd_case cmd_case)
{
	if (cmd_case == RRA)
	{
		if (_reverse_rotate(a))
			write(1, "rra\n", 4);
	}
	else if (cmd_case == RRB)
	{
		if (_reverse_rotate(b))
			write(1, "rrb\n", 4);
	}
	else if (cmd_case == RRR)
	{
		if (_reverse_rotate(a) && _reverse_rotate(b))
			write(1, "rrr\n", 4);
	}
}
