/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:35:14 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/29 18:58:15 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	_push(t_deque *push_deque, t_deque *pop_deque)
{
	t_node	*save;

	if (pop_deque->first == NULL)
		return (0);
	save = pop_deque->first;
	dq_pop_front(pop_deque);
	pop_deque->size--;
	dq_push_front(push_deque, save->value);
	push_deque->size++;
	push_deque->first->index = save->index;
	return (1);
}

void	push(t_deque *a, t_deque *b, t_cmd_case cmd_case)
{
	if (cmd_case == PA)
	{
		if (_push(a, b))
			write(1, "pa\n", 3);
	}
	else if (cmd_case == PB)
	{
		if (_push(b, a))
			write(1, "pb\n", 3);
	}
}
