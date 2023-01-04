/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:48:49 by junyoo            #+#    #+#             */
/*   Updated: 2023/01/04 21:27:04 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	_rotate(t_deque *deque)
{
	int		value;
	size_t	index;

	if (deque->first == NULL)
		return (0);
	value = deque->first->value;
	index = deque->first->index;
	dq_pop_front(deque);
	dq_push_back(deque, value);
	deque->last->index = index;
	return (1);
}

void	rotate(t_deque *a, t_deque *b, t_cmd_case cmd_case)
{
	if (cmd_case == RA)
	{
		if (_rotate(a))
			write(1, "ra\n", 3);
	}
	else if (cmd_case == RB)
	{
		if (_rotate(b))
			write(1, "rb\n", 3);
	}
	else if (cmd_case == RR)
	{
		if (_rotate(a) && _rotate(b))
			write(1, "rr\n", 3);
	}
}
