/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:29:05 by junyoo            #+#    #+#             */
/*   Updated: 2022/12/29 13:43:34 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

size_t	is_sorted(t_deque *a)
{
	t_node	*node;

	node = a->first;
	while (node->next)
	{
		if (node->index > node->next->index)
			return (a->size);
		node = node->next;
	}
	return (1);
}

void	basis_sort(t_deque *a)
{	
	return ;
}