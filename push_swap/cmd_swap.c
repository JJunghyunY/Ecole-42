/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:54:19 by junyoo            #+#    #+#             */
/*   Updated: 2023/01/09 16:58:03 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	_swap(t_deque *deque)
{
	int		value;
	size_t	index;

	if (deque->first == NULL || deque->first->next == NULL)
		return (0);
	value = deque->first->value;
	index = deque->first->index;
	deque->first->value = deque->first->next->value;
	deque->first->index = deque->first->next->index;
	deque->first->next->value = value;
	deque->first->next->index = index;
	return (1);
}

void	swap(t_deque *a, t_deque *b, t_cmd_case cmd_case)
{
	if (cmd_case == SA)
	{
		if (_swap(a))
			write(1, "sa\n", 3);
	}
	else if (cmd_case == SB)
	{
		if (_swap(b))
			write(1, "sb\n", 3);
	}
	else if (cmd_case == SS)
	{
		if (_swap(a) && _swap(b))
			write(1, "ss\n", 3);
	}
}
